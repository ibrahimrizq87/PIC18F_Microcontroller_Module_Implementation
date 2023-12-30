#include"hal_timer2.h"



#if TIMER2_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
static void (*TMR2_InterruptHandler) (void) = NULL;
#endif
static uint8 timer2_preload =0;

Std_ReturnType Timer2_Init(const timer2_t * timer2){

   Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer2){
        ret = E_NOT_OK;
    }else{
        TIMER2_MODULE_DISABLE();
        TIMER2_POSTSCALER_SELECT(timer2->postscaler_value);
        TIMER2_PRESCALER_SELECT(timer2->prescaler_value);

        TMR2 = timer2->timer2_preload_value;
        timer2_preload = timer2->timer2_preload_value;
#if TIMER2_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
 TIMER2_InterruptEnable();
 TIMER2_InterruptFlageClear();
 TMR2_InterruptHandler=timer2->TIMER2_InterruptHandler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
 INTERRUPT_PriorityLevelEnable();
if (timer2->prioprity == INTERRUPT_HIGH_PRIORITY){
    INTERRUPT_GlobalInterruptHighEnable();
    TIMER2_HighPrioritySet();
    
}else if (timer2->prioprity == INTERRUPT_LOW_PRIORITY){
    INTERRUPT_GlobalInterruptLowEnable();
TIMER2_LowPrioritySet();
}else{/*nothing*/}
#else
  INTERRUPT_GlobalInterruptEnable();
 INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
 

        TIMER2_MODULE_ENABLE();
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType Timer2_DeInit(const timer2_t * timer2){

   Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer2){
        ret = E_NOT_OK;
    }else{
        TIMER2_MODULE_DISABLE();
#if TIMER2_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
        TIMER2_InterruptDisable();
#endif
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType Timer2_Write_value(const timer2_t * timer2,uint8 value){

   Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer2){
        ret = E_NOT_OK;
    }else{
                TMR2 = value;
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType Timer2_Read_value(const timer2_t * timer2,uint8 *value){

   Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer2){
        ret = E_NOT_OK;
    }else{
        *value = TMR2;
        ret = E_OK;
    }
    return ret;
}

#if TIMER2_INTERRUPT_ENABLE ==1
void TIMER2_ISR(void){
    TIMER2_InterruptFlageClear();
    TMR2 = timer2_preload;
    if (TMR2_InterruptHandler){
        TMR2_InterruptHandler();
    }
}
#endif