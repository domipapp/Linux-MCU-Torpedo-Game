/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include <app.h>

/***************************************************************************//**
 * Globals.
 ******************************************************************************/
TaskHandle_t hTaskUart0;
TaskHandle_t hTaskLCD;
TaskHandle_t hTaskCursorBlink;

TimerHandle_t hMsTimer;

SemaphoreHandle_t RxValid;

QueueHandle_t UartData;

// Variable to be displayed
SegmentLCD_LowerCharSegments_TypeDef FIELD[SEGMENT_LCD_NUM_OF_LOWER_CHARS] = {0};
// variable to store hidden ships' positions
SegmentLCD_LowerCharSegments_TypeDef MAP[SEGMENT_LCD_NUM_OF_LOWER_CHARS];
// Variable to store current position of user cursor
SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS] = {0};
// Variable to store which ships have been hit
SegmentLCD_LowerCharSegments_TypeDef HIT[SEGMENT_LCD_NUM_OF_LOWER_CHARS] = {0};

volatile char rx_data;  // Global variable to "transport" received UART data
uint32_t game_time_100ms = 0; // Count elapsed time since start in 100ms
/***************************************************************************//**
 * ISRs.
 ******************************************************************************/
// Handles received data and signals prvTaskUart0 that new data has arrived
void UART0_RX_IRQHandler(void)
{
  BaseType_t xSwitchRequired;

  rx_data = USART_Rx(UART0);  // Reading data clears IF
  xSemaphoreGiveFromISR(RxValid, NULL);// Signal prvTaskUart0

  xSwitchRequired = xTaskResumeFromISR(hTaskUart0);

  portYIELD_FROM_ISR(xSwitchRequired);

}

/***************************************************************************//**
 * Callbacks
 ******************************************************************************/
// Timer Callback function. Increments game_time_100ms every 100ms
void vTimerCallback(void){
  game_time_100ms ++;
}
/***************************************************************************//**
 * User functions
 ******************************************************************************/
void Game_data_transmit(uint8_t shoots){
  xTimerStop(hMsTimer, portMAX_DELAY);
  char buffer[12];  // 32-bit value can always be represented in 11 characters (including null terminator), plus decimal point
  snprintf(buffer, sizeof(buffer), "%lu", game_time_100ms);  // Convert uint32_t to string to display in ASCII

  // Convert to seconds: Insert the decimal point before the last digit
  // There is always room for decimal point
  uint8_t length = strlen(buffer);  // Place of null terminator
  buffer[length + 1] = buffer[length];  // Move null terminator one place
  buffer[length] = buffer[length - 1];  // Move last digit one place
  buffer[length - 1] = '.';             // Insert decimal point before last digit

  // Send the string over USART
  for (int i = 0; buffer[i] != '\0'; i++) {
      USART_Tx(UART0, buffer[i]);// Send buffer[i] character over USART
  }
  USART_Tx(UART0, ' '); // Separate data with space

  USART_Tx(UART0, ('0' + shoots/10)); // Send first digit of shoot
  USART_Tx(UART0, ('0' + shoots%10)); // Send second digit of shoot
}

/***************************************************************************//**
 * FreeRTOS tasks.
 ******************************************************************************/
//  Pushes received data into Queue
static void prvTaskUart0(void *pvParam){
  while(1){
    vTaskSuspend(NULL);
    xSemaphoreTake(RxValid, portMAX_DELAY);
    xQueueSend(UartData, &rx_data, portMAX_DELAY);
  }
}

// This task h
static void prvTaskLCD(void *pvParam) {
  static uint8_t shoots = 0;  // Variable to store shots made
  SegmentLCD_Number(shoots);  // Display "0000" on LCD display
  char startFrame[3] = {0};   // Variable to store first 2 bytes to check valid start protocol frame
  static uint8_t hits = 0;    // Variable to store ships hit. 8 hits sinks all ships
  static bool start = true;   // Variable to check if start protocol is to be checked

  while(1){
      char c; // Variable to temporarily store UART data
      if(start){  // Start protocol is to be checked
          // Wait for 2 characters
          xQueueReceive(UartData, &c, portMAX_DELAY);
          startFrame[strlen(startFrame)] = c; // Add new char to next position in buffer
          xQueueReceive(UartData, &c, portMAX_DELAY);
          startFrame[strlen(startFrame)] = c; // Add new char to next position in buffer
          if(strcmp(startFrame, "xx") == 0){  // Correct frame is xx'num' where 0 < 'num' < 16
              // Receive two bytes and check map initialiser value
              xQueueReceive(UartData, &c, portMAX_DELAY);
              unsigned num = (unsigned) (c - '0');  // Convert ASCII to binary number
              num = num * 10;
              xQueueReceive(UartData, &c, portMAX_DELAY);
              num += (unsigned) (c - '0');  // Convert ASCII to binary number
              if(num < 16)
                init_map(MAP, num);
              else  // In case of incorrect initialiser map 0 is default
                init_map(MAP, 0);
              // Create and start timer to count game time. Ticks are generated every 100ms
              hMsTimer = xTimerCreate(NULL, pdMS_TO_TICKS(100), pdTRUE, ( void * ) 0, vTimerCallback);
              xTimerStart(hMsTimer, portMAX_DELAY);
              start = false;
          }
          else{ // Frame error, restart control process
              memset(startFrame, '\0', sizeof(startFrame));
              continue;
          }
      }
      // Display Cursor and hit ships
      SegmentLCD_LowerSegments(FIELD);
      // Waits until there is new and valid data
      xQueueReceive(UartData, &c, portMAX_DELAY);
      // Remove Cursor as its position will be changed. Otherwise interference with prvTaskCursorBlink
      FieldMinusCursor(FIELD, CURSOR_POS);
      switch (c) {
        case 'w':
          moveUp(CURSOR_POS);
          break;
        case 's':
          moveDown(CURSOR_POS);
          break;
        case 'a':
          moveLeft(CURSOR_POS);
          break;
        case 'd':
          moveRight(CURSOR_POS);
          break;
        case '\r':
        case '\n':
          // Increment and display new shoot value
          SegmentLCD_Number(++shoots);
          // Makes shooting effect
          SegmentLCD_ARingOnDelay(60);
          if(shoot(MAP, CURSOR_POS)){ // Check if ship has been hit
              if(isHit(HIT, CURSOR_POS)){  // Check if ship has been hit previously
                  SegmentLCD_ARingSet(false); // Kill ring display to signal unsuccessful shoot
                  break; // Break, so hit is not counted again
              }
              // Blink ring 3 times to signal successful shot
              SegmentLCD_ARingBlink(7, false, 400);
              // Save ship being hit
              hit(HIT, CURSOR_POS);
              hits ++;
          }
          else  // Kill ring display to signal unsuccessful shoot
            SegmentLCD_ARingSet(false);
          break;
        case 'q':
          Game_data_transmit(shoots); // Send relevant data back to PC
          // Display OVER string to signal pressing of q
          SegmentLCD_Write("OVER");
          vTaskSuspendAll(); // All Tasks are suspended to prevent display of other information
          vTaskSuspend(NULL);
          break;
        default:
          break;
      }
      // Save all sunken ships
      FieldPlusHit(FIELD, HIT);
      // Display new cursor position
      FieldPlusCursor(FIELD, CURSOR_POS);
      if(hits == 8){  // End of game
          Game_data_transmit(shoots); // Send relevant data back to PC
          // Display WINNER string to signal successful completion of game
          SegmentLCD_Write("WINNER");
          vTaskSuspendAll(); // All Tasks are suspended to prevent display of other information
          vTaskSuspend(NULL);
      }
  }
}

// This task blinks the current cursor position every 750 ms
static void prvTaskCursorBlink(void *pvParam)  {
  static bool PlusOrMinus = true; // Variable to check if segment needs to be turned on or off in order to display blinking effect
  while (1) {
      // Blink cursor
      if(PlusOrMinus)
        FieldPlusCursor(FIELD, CURSOR_POS); // Adds cursor to display
      else
        FieldMinusCursor(FIELD, CURSOR_POS);// Takes cursor out of display
      PlusOrMinus = !PlusOrMinus;
      // Display new configuration
      SegmentLCD_LowerSegments(FIELD);
      vTaskDelay(pdMS_TO_TICKS(750)); // Task runs every 750 ms
  }
}
/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  CHIP_Init();
  CMU_ClockEnable(cmuClock_GPIO, true); // Enable clock for gpio-s
  init_lcd(); // Turn LCD on
  init_vcom();// Configure UART for VCOM
  init_uart0(); // Configure UART0 for async
  init_cursor(CURSOR_POS);  // Give cursor a default starting place
  // Create semaphore
  RxValid = xSemaphoreCreateBinary();
  // Create Queue
  UartData = xQueueCreate(32, sizeof(uint8_t));
  if(UartData == NULL)  // If Queue couldn't be created, restart program
    NVIC_SystemReset();
  // Create tasks
  xTaskCreate(prvTaskUart0, "UART0",  configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, &hTaskUart0);
  xTaskCreate(prvTaskLCD, "LCD",  configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, &hTaskLCD);
  xTaskCreate(prvTaskCursorBlink, "CursorBlink",  configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &hTaskCursorBlink);
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
}
