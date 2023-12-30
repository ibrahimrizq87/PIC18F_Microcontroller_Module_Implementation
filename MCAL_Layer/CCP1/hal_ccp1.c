
#include"hal_ccp1.h"
#define _XTAL_FREQ 4000000UL


static void (*CCP1_InterruptHandler)(void) = NULL;


Std_ReturnType CCP1_Init(const CCP1_t* ccp_opj){
Std_ReturnType ret =E_OK;
if (ccp_opj == NULL){
    ret=E_NOT_OK;
}else{
    CCP1_SET_MODE(CCP1_MODULE_DISABLE);
    
    
    
    if (CCP1_CAPTURE_MODE_SELECT == ccp_opj->ccp1_mode){
    switch(ccp_opj->ccp1_mode_variant){
        case CCP1_CAPTURE_MODULE_1_FALING_EDGE: CCP1_SET_MODE(CCP1_CAPTURE_MODULE_1_FALING_EDGE);
            break;
        case CCP1_CAPTURE_MODULE_1_RISING_EDGE: CCP1_SET_MODE(CCP1_CAPTURE_MODULE_1_RISING_EDGE);
            break;
        case CCP1_CAPTURE_MODULE_16_RISING_EDGE: CCP1_SET_MODE(CCP1_CAPTURE_MODULE_16_RISING_EDGE);
            break;
        case CCP1_CAPTURE_MODULE_4_RISING_EDGE: CCP1_SET_MODE(CCP1_CAPTURE_MODULE_4_RISING_EDGE);
            break;
    default:ret = E_NOT_OK;
    
    }
    
    }else if (CCP1_COMPARE_MODE_SELECT == ccp_opj->ccp1_mode){
        switch(ccp_opj->ccp1_mode_variant){
        case CCP1_COMPARE_MODULE_SET_BIN_LOW: CCP1_SET_MODE(CCP1_COMPARE_MODULE_SET_BIN_LOW);
            break;
        case CCP1_COMPARE_MODULE_SET_BIN_HIGH: CCP1_SET_MODE(CCP1_COMPARE_MODULE_SET_BIN_HIGH);
            break;
        case CCP1_CAPTURE_MODULE_16_RISING_EDGE: CCP1_SET_MODE(CCP1_CAPTURE_MODULE_16_RISING_EDGE);
            break;
        case CCP1_COMPARE_MODULE_TOGGLE_ON_MATCH: CCP1_SET_MODE(CCP1_COMPARE_MODULE_TOGGLE_ON_MATCH);
            break;
    case CCP1_COMPARE_MODULE_GEN_SW_INTERRUPT: CCP1_SET_MODE(CCP1_COMPARE_MODULE_GEN_SW_INTERRUPT);
            break;
        case CCP1_COMPARE_MODULE_GEN_EVENT: CCP1_SET_MODE(CCP1_COMPARE_MODULE_GEN_EVENT);
            break;
            default:ret = E_NOT_OK;
        }    
    }else if (CCP1_PWM_MODE_SELECT == ccp_opj->ccp1_mode){
    ret = E_NOT_OK;
    #if (CCP1_MODULE_SELECTED == CCP1_PWM_MODULE_ENABLE)
        if (ccp_opj->ccp1_mode_variant == CCP1_PWM_MODE){
        CCP1_SET_MODE(CCP1_PWM_MODE);
        PR2 =(uint8)((_XTAL_FREQ/(ccp_opj->postscaler_value * ccp_opj->prescaler_value * 4.0 * ccp_opj->pwm_frequancy))-1);     
        ret = E_OK;
        }
    #endif
    }
    
    ret =gpio_pin_intialize(&(ccp_opj->pin));
    
    
#if CCP1_INTERRUPT_ENABLE ==1
    CCP1_InterruptEnable();
    CCP1_InterruptFlageClear();
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
if (ccp_opj->prioprity == INTERRUPT_HIGH_PRIORITY){
    CCP1_HighPrioritySet();
}else if (ccp_opj->prioprity == INTERRUPT_LOW_PRIORITY){
CCP1_LowPrioritySet();
}else{/*nothing*/}
#else
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
#endif

 CCP1_InterruptHandler = ccp_opj->CCP1_InterruptHandler;
#endif

    
}
return ret;
}
Std_ReturnType CCP1_Deinit(const CCP1_t* ccp_opj){
Std_ReturnType ret =E_OK;
if (ccp_opj == NULL){
    ret=E_NOT_OK;
}else{
    CCP1_SET_MODE(CCP1_MODULE_DISABLE);
#if CCP1_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
    CCP1_InterruptDisable();   
#endif
}
return ret;
}

#if (CCP1_MODULE_SELECTED == CCP1_CAPTURE_MODULE_ENABLE)
Std_ReturnType CCP1_Is_Capture_Data_Ready(uint8* status){
Std_ReturnType ret =E_OK;
if (status == NULL){
    ret=E_NOT_OK;
}else{
    if (CCP1_CAPTURE_READY == PIR1bits.CCP1IF){
    *status=CCP1_CAPTURE_READY;
    CCP1_InterruptFlageClear();
    }else if (CCP1_CAPTURE_NOT_READY == PIR1bits.CCP1IF){
    *status=CCP1_CAPTURE_NOT_READY;
    
    }
}
return ret;
}
Std_ReturnType CCP1_Capture_Data(uint16* data){
Std_ReturnType ret =E_OK;
CCP_PERIOD_REG_t caputerValue={.ccp1_low=0 ,.ccp1_high =0};
if (data == NULL){
    ret=E_NOT_OK;
}else{
    caputerValue.ccp1_low = CCPR1L;
    caputerValue.ccp1_high = CCPR1H;
    
*data = caputerValue.ccpr1_16Bit;
}
return ret;
}
#endif

#if (CCP1_MODULE_SELECTED == CCP1_COMPERE_MODULE_ENABLE)
Std_ReturnType CCP1_Is_Compare_Complete(uint8 *status){
Std_ReturnType ret =E_OK;
CCP_PERIOD_REG_t caputerValue={.ccp1_low=0 ,.ccp1_high =0};

if (status == NULL){
    ret=E_NOT_OK;
}else{
    if (CCP1_COMPARE_READY  == PIR1bits.CCP1IF){
    *status=CCP1_COMPARE_READY ;
    CCP1_InterruptFlageClear();
    }else if (CCP1_COMPARE_NOT_READY  == PIR1bits.CCP1IF){
    *status=CCP1_COMPARE_NOT_READY ;
    
    }
}
return ret;
}
Std_ReturnType CCP1_Compare_mode_steValue(uint16 value){
Std_ReturnType ret =E_OK;
CCP_PERIOD_REG_t caputerValue={.ccp1_low=0 ,.ccp1_high =0};
caputerValue.ccpr1_16Bit = status;
 CCPR1L = caputerValue.ccp1_low;
    CCPR1H = caputerValue.ccp1_high;
return ret;
}

#endif

#if (CCP1_MODULE_SELECTED == CCP1_PWM_MODULE_ENABLE)
Std_ReturnType CCP1_set_duty(uint8 value)
{
Std_ReturnType ret =E_OK;
uint16 duty_value=0;
duty_value=(uint16)((PR2+1)*(value/100.0));
CCP1CONbits.DC1B = (uint8)(duty_value & 0x0003);
CCPR1L =  (uint8)(duty_value >>2);
return ret;
}
Std_ReturnType CCP1_start(void)
{
Std_ReturnType ret =E_OK;
CCP1CONbits.CCP1M = CCP1_PWM_MODE;
return ret;
}
Std_ReturnType CCP1_stop(void)
        {
Std_ReturnType ret =E_OK;
CCP1CONbits.CCP1M = CCP1_MODULE_DISABLE;
return ret;
}
#endif
