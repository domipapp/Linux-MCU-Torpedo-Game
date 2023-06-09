#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[ACMP0]
// [ACMP0]$

// $[ACMP1]
// [ACMP1]$

// $[ADC0]
// [ADC0]$

// $[BU]
// [BU]$

// $[CMU]
// [CMU]$

// $[DAC0]
// [DAC0]$

// $[DBG]
// [DBG]$

// $[EBI]
// [EBI]$

// $[ETM]
// [ETM]$

// $[GPIO]
// [GPIO]$

// $[HFXO]
// [HFXO]$

// $[I2C0]
// [I2C0]$

// $[I2C1]
// [I2C1]$

// $[LCD]
// [LCD]$

// $[LESENSE]
// [LESENSE]$

// $[LETIMER0]
// [LETIMER0]$

// $[LEUART0]
// [LEUART0]$

// $[LEUART1]
// [LEUART1]$

// $[LFXO]
// [LFXO]$

// $[PCNT0]
// [PCNT0]$

// $[PCNT1]
// [PCNT1]$

// $[PCNT2]
// [PCNT2]$

// $[PRS.CH0]
// [PRS.CH0]$

// $[PRS.CH1]
// [PRS.CH1]$

// $[PRS.CH2]
// [PRS.CH2]$

// $[PRS.CH3]
// [PRS.CH3]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[TIMER2]
// [TIMER2]$

// $[TIMER3]
// [TIMER3]$

// $[UART0]
// UART0 RX on PE1
#define UART0_RX_PORT                            gpioPortE
#define UART0_RX_PIN                             1
#define UART0_ROUTE_LOC                          1

// UART0 TX on PE0
#define UART0_TX_PORT                            gpioPortE
#define UART0_TX_PIN                             0

// [UART0]$

// $[UART1]
// [UART1]$

// $[USART0]
// [USART0]$

// $[USART1]
// [USART1]$

// $[USART2]
// [USART2]$

// $[USB]
// [USB]$

// $[CUSTOM_PIN_NAME]
#define PB0_PORT                                 gpioPortB
#define PB0_PIN                                  9

#define PB1_PORT                                 gpioPortB
#define PB1_PIN                                  10

#define VCOM_PORT                                gpioPortF
#define VCOM_PIN                                 7

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

