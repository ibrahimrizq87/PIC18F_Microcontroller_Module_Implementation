/* 
 * File:   hal_timer3.h
 * Author: Ibrahim BEMO
 *
 * Created on November 17, 2023, 1:16 PM
 */

#ifndef HAL_TIMER3_H
#define	HAL_TIMER3_H



/* Section : Includes */

#include "pic18f4620.h"
#include"../GPIO/hal_gpio.h"
#include"../Interrupt/mcal_internal_interrupt.h"
#include"../../MCAL_Layer/mcal_std_types.h"

/* Section: Macro Declarations */

#define TIMER3_TIMER_MODE 0
#define TIMER3_COUNTER__MODE 1

#define TIMER3_ASYNC_COUNTER_MODE 1
#define TIMER3_SYNC_COUNTER_MODE  0

#define TIMER3_PRESCALER_DIV_BY_1 0
#define TIMER3_PRESCALER_DIV_BY_2 1
#define TIMER3_PRESCALER_DIV_BY_4 2
#define TIMER3_PRESCALER_DIV_BY_8 3

#define TIMER3_RW_REG_8BIT_MODE   0
#define TIMER3_RW_REG_16BIT_MODE  1

/* Section: Macro Functions Declarations */
#define TIMER3_RW_REG_8BIT_MODE_ENABLE()     (T3CONbits.RD16 = 0)
#define TIMER3_RW_REG_16BIT_MODE_DISABLE()   (T3CONbits.RD16 = 1)


#define TIMER3_MODULE_ENABLE()               (T3CONbits.TMR3ON = 1)
#define TIMER3_MODULE_DISABLE()              (T3CONbits.TMR3ON = 0)

#define TIMER3_TIMER_MODE_ENABLE()           (T3CONbits.TMR3CS = 0)
#define TIMER3_COUNTER_MODE_ENABLE()         (T3CONbits.TMR3CS = 1)


#define TIMER3_ASYNC_COUNTER_MODE_ENABLE()   (T3CONbits.T3SYNC = 1)
#define TIMER3_SYNC_COUNTER_MODE_ENABLE()    (T3CONbits.T3SYNC = 0)

#define TIMER3_PRESCALER_SELECT(_PRESCALER_) (T3CONbits.T3CKPS = _PRESCALER_)

/* Section: Data Type Declarations */
typedef struct{
    #if TIMER3_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
void (*TIMER3_InterruptHandler) (void);
    interrupt_priority_cfg prioprity;
#endif
    uint16 timer3_preload_value;
    uint8 timer3_prescaler_value :2;
    uint8 timer3_mode :1;
    uint8 timer3_counter_mode :1;
    uint8 timer3_register_RW_mode :1;
    uint8 timer3_reserved:3;
    
}timer3_t;
/* Section: Function Declarations */
Std_ReturnType Timer3_Init(const timer3_t * timer3);
Std_ReturnType Timer3_DeInit(const timer3_t * timer3);
Std_ReturnType Timer3_Write_value(const timer3_t * timer3,uint16 value);
Std_ReturnType Timer3_Read_value(const timer3_t * timer3,uint16 *value);



#endif	/* HAL_TIMER3_H */

