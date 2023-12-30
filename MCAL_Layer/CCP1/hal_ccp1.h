/* 
 * File:   hal_ccp1.h
 * Author: Ibrahim BEMO
 *
 * Created on November 18, 2023, 9:14 PM
 */

#ifndef HAL_CCP1_H
#define	HAL_CCP1_H

#include"hal_ccp1_cfg.h"
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include"../../MCAL_Layer/GPIO/hal_gpio.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"

/* CCP Mode Select*/
#define CCP1_MODULE_DISABLE                       (uint8)0x00
#define CCP1_CAPTURE_MODULE_1_FALING_EDGE         (uint8)0x04
#define CCP1_CAPTURE_MODULE_1_RISING_EDGE         (uint8)0x05
#define CCP1_CAPTURE_MODULE_4_RISING_EDGE         (uint8)0x06
#define CCP1_CAPTURE_MODULE_16_RISING_EDGE        (uint8)0x07
#define CCP1_COMPARE_MODULE_SET_BIN_LOW           (uint8)0x08
#define CCP1_COMPARE_MODULE_SET_BIN_HIGH          (uint8)0x09
#define CCP1_COMPARE_MODULE_TOGGLE_ON_MATCH       (uint8)0x02
#define CCP1_COMPARE_MODULE_GEN_SW_INTERRUPT      (uint8)0x0A
#define CCP1_COMPARE_MODULE_GEN_EVENT             (uint8)0x0B
#define CCP1_PWM_MODE                             (uint8)0x0C

/* capture mode status */
#define CCP1_CAPTURE_NOT_READY                    0x00
#define CCP1_CAPTURE_READY                        0x01
/* compare mode status */
#define CCP1_COMPARE_NOT_READY                    0x00
#define CCP1_COMPARE_READY                        0x01


#define CCP1_SET_MODE(_CONFIG) (CCP1CONbits.CCP1M = _CONFIG)


typedef enum{
    CCP1_CAPTURE_MODE_SELECT = 0,
    CCP1_COMPARE_MODE_SELECT,
    CCP1_PWM_MODE_SELECT
}ccp1_mode;


typedef union{
    struct{
        uint8 ccp1_low;
        uint8 ccp1_high;
    };
    struct{
    uint16 ccpr1_16Bit;
    };
}CCP_PERIOD_REG_t;



typedef struct{
ccp1_mode ccp1_mode;
uint8 ccp1_mode_variant;
pin_config_t pin;
#if CCP1_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
void (*CCP1_InterruptHandler) (void);
interrupt_priority_cfg prioprity;
#endif


#if (CCP1_MODULE_SELECTED == CCP1_PWM_MODULE_ENABLE)
uint32 pwm_frequancy;
uint8 prescaler_value :2;
uint8 postscaler_value :4 ;
#endif

}CCP1_t;


Std_ReturnType CCP1_Init(const CCP1_t* ccp_opj);
Std_ReturnType CCP1_Deinit(const CCP1_t* ccp_opj);

#if (CCP1_MODULE_SELECTED == CCP1_CAPTURE_MODULE_ENABLE)
Std_ReturnType CCP1_Is_Capture_Data_Ready(uint8* status);
Std_ReturnType CCP1_Capture_Data(uint16* data);
#endif

#if (CCP1_MODULE_SELECTED == CCP1_COMPERE_MODULE_ENABLE)
Std_ReturnType CCP1_Is_Compare_Complete(uint8* status);
Std_ReturnType CCP1_Compare_mode_steValue(uint16 value);

#endif

#if (CCP1_MODULE_SELECTED == CCP1_PWM_MODULE_ENABLE)
Std_ReturnType CCP1_set_duty(uint32 value);
Std_ReturnType CCP1_start(void);
Std_ReturnType CCP1_stop(void);
#endif

#endif	/* HAL_CCP1_H */

