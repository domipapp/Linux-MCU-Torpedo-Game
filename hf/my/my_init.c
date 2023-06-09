#include "my_init.h"

// Initialise LCD without voltage boost
void init_lcd(void){
  SegmentLCD_Init(false);
}

// Set appropriate pin for UART0 to use vcom port
void init_vcom(void){
  GPIO_PinModeSet(VCOM_PORT, VCOM_PIN, gpioModePushPull, 1);
}

// Initialise UART0 for async use
void init_uart0(void){
  // Enable oscillator to UART module
  CMU_ClockEnable(cmuClock_UART0, true);
  // Set pin modes for UART TX and RX pins
  GPIO_PinModeSet(UART0_TX_PORT, UART0_TX_PIN, gpioModePushPull, 1);
  GPIO_PinModeSet(UART0_RX_PORT, UART0_RX_PIN, gpioModeInput, 0);
  // Initialize USART asynchronous mode and route pins
  USART_InitAsync_TypeDef init = USART_INITASYNC_DEFAULT;
  USART_InitAsync(UART0, &init);
  UART0->ROUTE |= UART_ROUTE_TXPEN | UART_ROUTE_RXPEN | UART_ROUTE_LOCATION_LOC1;
  //Initialise USART Interrupt
  USART_IntEnable(UART0, UART_IEN_RXDATAV);
  //Enabling USART Interrupts
  NVIC_EnableIRQ(UART0_RX_IRQn);
}

// Initialises MAP with one preconfigured ship layout
void init_map(SegmentLCD_LowerCharSegments_TypeDef MAP[SEGMENT_LCD_NUM_OF_LOWER_CHARS], unsigned level){
  // Check for invalid request
  if(level > SAVED_MAP_NUMBERS - 1)
    return;
  // Copy data, .raw doesn't work
  for(int i = 0; i < SEGMENT_LCD_NUM_OF_LOWER_CHARS; i ++){
    MAP[i].a = game_levels[level][i][0];
    MAP[i].b = game_levels[level][i][1];
    MAP[i].c = game_levels[level][i][2];
    MAP[i].d = game_levels[level][i][3];
    MAP[i].e = game_levels[level][i][4];
    MAP[i].f = game_levels[level][i][5];
    MAP[i].g = game_levels[level][i][6];
    MAP[i].h = game_levels[level][i][7];
    MAP[i].j = game_levels[level][i][8];
    MAP[i].k = game_levels[level][i][9];
    MAP[i].m = game_levels[level][i][10];
    MAP[i].n = game_levels[level][i][11];
    MAP[i].p = game_levels[level][i][12];
    MAP[i].q = game_levels[level][i][13];
  }

}


