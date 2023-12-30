
#include"hal_timer1.h"
#if TIMER1_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
static void (*TMR1_InterruptHandler) (void) = NULL;
#endif
static uint16 timer1_preload =0;
static inline void timer1_mode_select(const timer0_t * timer0);

Std_ReturnType Timer1_Init(const timer1_t * timer1){
    Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer1){
        ret = E_NOT_OK;
    }else{
        TIMER1_MODULE_DISABLE();
       TIMER1_PRESCALER_SELECT(timer1->timer1_prescaler_value);
        timer1_mode_select(timer1);
        
        TMR1H = (timer1->timer1_preload_value)>>8;
        TMR1L =(uint8)(timer1->timer1_preload_value);
        timer1_preload = timer1->timer1_preload_value;
#if TIMER0_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
 TIMER1_InterruptEnable();
 TIMER1_InterruptFlageClear();
 TMR1_InterruptHandler=timer1->TIMER1_InterruptHandler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
 INTERRUPT_PriorityLevelEnable();
if (timer1->prioprity == INTERRUPT_HIGH_PRIORITY){
    INTERRUPT_GlobalInterruptHighEnable();
    TIMER1_HighPrioritySet();
    
}else if (timer1->prioprity == INTERRUPT_LOW_PRIORITY){
    INTERRUPT_GlobalInterruptLowEnable();
TIMER1_LowPrioritySet();
}else{/*nothing*/}
#else
  INTERRUPT_GlobalInterruptEnable();
 INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
 
        TIMER1_MODULE_ENABLE();
        
    ret = E_OK;
    }
    return ret;
}
Std_ReturnType Timer1_DeInit(const timer1_t * timer1){

   Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer1){
        ret = E_NOT_OK;
    }else{
        TIMER1_MODULE_DISABLE();
#if TIMER1_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
        TIMER1_InterruptDisable();
#endif
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType Timer1_Write_value(const timer1_t * timer1,uint16 value){

   Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer1){
        ret = E_NOT_OK;
    }else{
        TMR1H = (value)>>8;
        TMR1L =(uint8)(value);
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType Timer1_Read_value(const timer1_t * timer1,uint16 *value){
    Std_ReturnType ret =E_NOT_OK;
    uint8 L_TMR1L =0;
    uint8 L_TMR1H =0;
    
    if ((NULL == timer1)||(NULL == value)){
        ret = E_NOT_OK;
    }else{
        L_TMR1L = TMR1L;
        L_TMR1H = TMR1H;
        *value = (uint16)((TMR1H<<8)+TMR1L);
    }
    return ret;
}


static inline void timer1_mode_select(const timer1_t * timer1){
    if (TIMER1_TIMER_MODE == timer1->timer1_mode){
        TIMER1_TIMER_MODE_ENABLE();
    }else if (TIMER1_COUNTER__MODE== timer1->timer1_mode)
            {
           TIMER1_COUNTER_MODE_ENABLE();
           if (TIMER1_ASYNC_COUNTER_MODE==timer1->timer1_counter_mode)
           {
              TIMER1_ASYNC_COUNTER_MODE_ENABLE(); 
           }else if (TIMER1_SYNC_COUNTER_MODE==timer1->timer1_counter_mode)
           {
               TIMER1_SYNC_COUNTER_MODE_ENABLE();
           }else{/* nothing */}
    }else{/* nothing */}
}
#if TIMER1_INTERRUPT_ENABLE ==1
void TIMER1_ISR(void){
    TIMER1_InterruptFlageClear();
    TMR1H = (timer1_preload)>>8;
    TMR1L =(uint8)(timer1_preload);
    if (TMR1_InterruptHandler){
        TMR1_InterruptHandler();
    }
}
#endif