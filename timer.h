



#ifndef TIMER_H_
#define TIMER_H_



/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include <LPC17xx.h>
/* Private typedef -----------------------------------------------------------*/
enum {TIMER_0=0,TIMER_1,TIMER_2,TIMER_3};
enum {TIMER_COUNTER_DISABLE=0,TIMER_COUNTER_ENABLE};
enum {PRESCALE_COUNTER_DISABLE=0,PRESCALE_COUNTER_ENABLE};
enum {TIMER_MODE=0,TC_INCREMENT_RISING_EDGE,TC_INCREMENT_FALLING_EDGE,TC_INCREMENT_BOTH_EDGE};
enum {CAPn_0=0,CAPn_1};

/* Private define ------------------------------------------------------------*/

/* Prescalar values for 1us, 1ms and 1 sec for peripheral clock 25MHz */
#define PRESCALAR_US        25
#define PRESCALAR_MS        25000
#define PRESCALAR_SEC       25000000


#define TIMER0   LPC_TIM0
#define TIMER1   LPC_TIM1
#define TIMER2   LPC_TIM2
#define TIMER3   LPC_TIM3






/*Bits in Interrupt Register (T[0/1/2/3]IR - 0x4000 4000, 0x4000 8000, 0x4009 0000, 0x4009 4000)*/
#define BIT_IR_MR0INT                    0
#define BIT_IR_MR1INT                    1
#define BIT_IR_MR2INT                    2
#define BIT_IR_MR3INT                    3
#define BIT_IR_CR0INT                    4
#define BIT_IR_CR1INT                    5

/*Bits in Timer Control Register
(TCR, TIMERn: TnTCR - addresses 0x4000 4004, 0x4000 8004, 0x4009 0004, 0x4009 4004)*/
#define BIT_TCR_COUNTER_ENABLE			 0
#define BIT_TCR_COUNTER_RESET  			 1

/*Bits in Count Control Register
(T[0/1/2/3]CTCR - addresses 0x4000 4070, 0x4000 8070, 0x4009 0070, 0x4009 4070)*/
#define BIT_CTCR_COUNTER_TIMER_MODE          0
#define BIT_CTCR_COUNTER_INPUT_SELECT        2

/*Bits in Match Control Register
(T[0/1/2/3]MCR - addresses 0x4000 4014, 0x4000 8014, 0x4009 0014, 0x4009 4014)*/
#define BIT_MCR_MR0I		       0
#define BIT_MCR_MR0R		       1
#define BIT_MCR_MR0S		       2
#define BIT_MCR_MR1I		       3
#define BIT_MCR_MR1R		       4
#define BIT_MCR_MR1S		       5
#define BIT_MCR_MR2I		       6
#define BIT_MCR_MR2R		       7
#define BIT_MCR_MR2S		       8
#define BIT_MCR_MR3I		       9
#define BIT_MCR_MR3R		       10
#define BIT_MCR_MR3S		       11

/*Bits in Capture Control Register
(T[0/1/2/3]CCR - addresses 0x4000 4028, 0x4000 8020, 0x4009 0028, 0x4009 4028)*/
#define BIT_CCR_CAP0RE		       0
#define BIT_CCR_CAP0FE		       1
#define BIT_CCR_CAP0I		       2
#define BIT_CCR_CAP1RE		       3
#define BIT_CCR_CAP1FE		       4
#define BIT_CCR_CAP1I		       5

/*Bits in External Match Register
(T[0/1/2/3]EMR - addresses 0x4000 403C, 0x4000 803C, 0x4009 003C, 0x4009 403C)*/
#define BIT_EMR_EM0		       	   0
#define BIT_EMR_EM1		       	   1
#define BIT_EMR_EM2		           2
#define BIT_EMR_EM3		           3
#define BIT_EMR_EMC0		       4
#define BIT_EMR_EMC1		       6
#define BIT_EMR_EMC2		       8
#define BIT_EMR_EMC3		       10






/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/**
 * @brief     Initializing the selected TIMER Peripheral
 * @param[in] ucTIMERNum value can be TIMER_0, TIMER_1, TIMER_2, TIMER_3
 * @return    No return value
 **/

void vTimerInitialize(uint8_t ucTIMERNum);


/**
 * @brief     Generating delay in milliseconds using polling method for the selected timer peripheral
 * @param[in] TIMERx value can be TIMER0,TIMER1,TIMER2,TIMER3
 * @param[in] delayinms value can be 32 bit integer value
 * @return    No return value
 **/
void vTimerDelayinMs(LPC_TIM_TypeDef* TIMERx,uint32_t delayinms);
/**
 * @brief     Generating delay in microseconds using polling method for the selected timer peripheral
 * @param[in] TIMERx value can be TIMER0,TIMER1,TIMER2,TIMER3
 * @param[in] delayinus value can be 32 bit integer value
 * @return    No return value
 **/
void vTimerDelayinUs(LPC_TIM_TypeDef* TIMERx,uint32_t delayinus);

/**
 * @brief     Generating delay in seconds using polling method for the selected timer peripheral
 * @param[in] TIMERx value can be TIMER0,TIMER1,TIMER2,TIMER3
 * @param[in] delayinsecs value can be 32 bit integer value
 * @return    No return value
 **/
void vTimerDelayinSecs(LPC_TIM_TypeDef* TIMERx,uint32_t delayinsecs);







#endif /* TIMER_H_ */
