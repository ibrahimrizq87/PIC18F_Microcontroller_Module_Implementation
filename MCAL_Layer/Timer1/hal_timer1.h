/* 
 * File:   hal_timer1.h
 * Author: Ibrahim BEMO
 *
 * Created on November 17, 2023, 12:01 AM
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/* Section : Includes */

#include "pic18f4620.h"
#include"../GPIO/hal_gpio.h"
#include"../Interrupt/mcal_internal_interrupt.h"
#include"../../MCAL_Layer/mcal_std_types.h"

/* Section: Macro Declarations */

#define TIMER1_TIMER_MODE 0
#define TIMER1_COUNTER__MODE 1

#define TIMER1_ASYNC_COUNTER_MODE 1
#define TIMER1_SYNC_COUNTER_MODE  0

#define TIMER1_OSC_ENABLE   1
#define TIMER1_OSC_DISABLE  0


#define TIMER1_PRESCALER_DIV_BY_1 0
#define TIMER1_PRESCALER_DIV_BY_2 1
#define TIMER1_PRESCALER_DIV_BY_4 2
#define TIMER1_PRESCALER_DIV_BY_8 3

#define TIMER1_RW_REG_8BIT_MODE   0
#define TIMER1_RW_REG_16BIT_MODE  1
/* Section: Macro Functions Declarations */
#define TIMER1_RW_REG_8BIT_MODE_ENABLE()     (T1CONbits.RD16 = 0)
#define TIMER1_RW_REG_16BIT_MODE_DISABLE()   (T1CONbits.RD16 = 1)


#define TIMER1_MODULE_ENABLE()               (T1CONbits.TMR1ON = 1)
#define TIMER1_MODULE_DISABLE()              (T1CONbits.TMR1ON = 0)

#define TIMER1_TIMER_MODE_ENABLE()           (T1CONbits.TMR1CS = 0)
#define TIMER1_COUNTER_MODE_ENABLE()         (T1CONbits.TMR1CS = 1)


#define TIMER1_ASYNC_COUNTER_MODE_ENABLE()   (T1CONbits.T1SYNC = 1)
#define TIMER1_SYNC_COUNTER_MODE_ENABLE()    (T1CONbits.T1SYNC = 0)

#define TIMER1_OSC_MODE_ENABLE()             (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSC_MODE_DISABLE()            (T1CONbits.T1OSCEN = 0)

#define TIMER1_PRESCALER_SELECT(_PRESCALER_) (T1CONbits.T1CKPS = _PRESCALER_)

#define TIMER1_SYSTEM_CLK_STATUS()           (T1CONbits.T1RUN)
/* Section: Data Type Declarations */
typedef struct{
    #if TIMER1_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
void (*TIMER1_InterruptHandler) (void);
    interrupt_priority_cfg prioprity;
#endif
    uint16 timer1_preload_value;
    uint8 timer1_prescaler_value :2;
    uint8 timer1_mode :1;
    uint8 timer1_counter_mode :1;
    uint8 timer1_osc_mode :1;
    uint8 timer1_register_RW_mode :1;
    uint8 timer1_reserved:2;
    
}timer1_t;
/* Section: Function Declarations */
Std_ReturnType Timer1_Init(const timer1_t * timer1);
Std_ReturnType Timer1_DeInit(const timer1_t * timer1);
Std_ReturnType Timer1_Write_value(const timer1_t * timer1,uint16 value);
Std_ReturnType Timer1_Read_value(const timer1_t * timer1,uint16 *value);
#endif	/* HAL_TIMER1_H */

