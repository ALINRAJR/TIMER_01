/*
===============================================================================
 Name        : 30_Day66_23112021_TIMER001.c

 Description : Program to demonstrate the TIMER Polling Method

 TODO        :

 Layered Architecture used for this project
 ************************************
 Application layer-30_Day66_23112021_TIMER001.c
 ************************************
 Board layer -  configboard.h, led.c/.h
 ************************************
 Low level drivers or chip level - pinmux.c/.h,timer.c/.h, gpio.c/.h
 ************************************
 Hardware
 ************************************
===============================================================================
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "pinmux.h"
#include "timer.h"
#include "led.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{
	vPinmuxInitialize();
	vLedInitialize();
	vTimerInitialize(TIMER_2);
}


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {

		vLedOn(LED_0);
		vTimerDelayinMs(TIMER2, 500);
		vLedOff(LED_0);
		vTimerDelayinMs(TIMER2, 500);

		vLedOn(LED_0);
		vTimerDelayinUs(TIMER2, 1000000);
		vLedOff(LED_0);
		vTimerDelayinUs(TIMER2, 1000000);

		vLedOn(LED_0);
		vTimerDelayinSecs(TIMER0, 3);
		vLedOff(LED_0);
		vTimerDelayinSecs(TIMER0, 3);



  }
  /* End of Application entry point */
}



