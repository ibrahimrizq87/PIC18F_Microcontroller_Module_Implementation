/* 
 * File:   hal_timer2.h
 * Author: Ibrahim BEMO
 *
 * Created on November 17, 2023, 11:07 AM
 */

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H

#include "pic18f4620.h"
#include"../GPIO/hal_gpio.h"
#include"../Interrupt/mcal_internal_interrupt.h"
#include"../../MCAL_Layer/mcal_std_types.h"




/* Section : Includes */

/* Section: Macro Declarations */
#define TIMER2_PRESCALER_DIV_BY_1 0
#define TIMER2_PRESCALER_DIV_BY_4 1
#define TIMER2_PRESCALER_DIV_BY_16 2

/* Section: Macro Functions Declarations */
#define TIMER2_MODULE_ENABLE() (T2CONbits.TMR0ON = 1)
#define TIMER2_MODULE_DISABLE() (T2CONbits.TMR0ON = 0)
#define TIMER2_PRESCALER_SELECT(_PRESCALER_) (T2CONbits.T2CKPS = _PRESCALER_)
#define TIMER2_POSTSCALER_SELECT(_PRESCALER_) (T2CONbits.TOUTPS = _PRESCALER_)
/* Section: Data Type Declarations */

typedef enum{
            TIMER2_POSTSCALER_DIV_BY_1 = 0,
            TIMER2_POSTSCALER_DIV_BY_2,
            TIMER2_POSTSCALER_DIV_BY_3,
            TIMER2_POSTSCALER_DIV_BY_4,
            TIMER2_POSTSCALER_DIV_BY_5,
            TIMER2_POSTSCALER_DIV_BY_6,
            TIMER2_POSTSCALER_DIV_BY_7,
            TIMER2_POSTSCALER_DIV_BY_8,
            TIMER2_POSTSCALER_DIV_BY_9,
            TIMER2_POSTSCALER_DIV_BY_10,
            TIMER2_POSTSCALER_DIV_BY_11,
            TIMER2_POSTSCALER_DIV_BY_12,
            TIMER2_POSTSCALER_DIV_BY_13,
            TIMER2_POSTSCALER_DIV_BY_14,
            TIMER2_POSTSCALER_DIV_BY_15,
            TIMER2_POSTSCALER_DIV_BY_16
}timer2_postscaler_select_t;

typedef struct{
    #if TIMER2_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
void (*TIMER2_InterruptHandler) (void);
    interrupt_priority_cfg prioprity;
#endif
    uint8 timer2_preload_value ;
    uint8 prescaler_value :2;
    timer2_postscaler_select_t postscaler_value ;
    uint8 timer2_reserved:2;
    
}timer2_t;
/* Section: Function Declarations */
Std_ReturnType Timer2_Init(const timer2_t * timer2);
Std_ReturnType Timer2_DeInit(const timer2_t * timer2);
Std_ReturnType Timer2_Write_value(const timer2_t * timer2,uint8 value);
Std_ReturnType Timer2_Read_value(const timer2_t * timer2,uint8 *value);
#endif	/* HAL_TIMER2_H */

