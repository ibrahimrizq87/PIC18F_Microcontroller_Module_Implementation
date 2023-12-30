#include"hal_timer3.h"


#if TIMER3_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
static void (*TMR3_InterruptHandler) (void) = NULL;
#endif
static uint16 timer3_preload =0;

 
static inline void timer3_mode_select(const timer3_t * timer3);
Std_ReturnType Timer3_Init(const timer3_t * timer3){
     Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer3){
        ret = E_NOT_OK;
    }else{
        TIMER3_MODULE_DISABLE();
       TIMER3_PRESCALER_SELECT(timer3->timer3_prescaler_value);
        timer3_mode_select(timer3);
        
        TMR3H = (timer3->timer3_preload_value)>>8;
        TMR3L =(uint8)(timer3->timer3_preload_value);
        timer3_preload = timer3->timer3_preload_value;
#if TIMER3_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
 TIMER3_InterruptEnable();
 TIMER3_InterruptFlageClear();
 TMR3_InterruptHandler=timer3->TIMER3_InterruptHandler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
 INTERRUPT_PriorityLevelEnable();
if (timer3->prioprity == INTERRUPT_HIGH_PRIORITY){
    INTERRUPT_GlobalInterruptHighEnable();
    TIMER3_HighPrioritySet();
    
}else if (timer3->prioprity == INTERRUPT_LOW_PRIORITY){
    INTERRUPT_GlobalInterruptLowEnable();
TIMER3_LowPrioritySet();
}else{/*nothing*/}
#else
  INTERRUPT_GlobalInterruptEnable();
 INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
 
        TIMER3_MODULE_ENABLE();
        
    ret = E_OK;
    }
    return ret;
}
    
Std_ReturnType Timer3_DeInit(const timer3_t * timer3){

   Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer3){
        ret = E_NOT_OK;
    }else{
        TIMER3_MODULE_DISABLE();
#if TIMER3_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
        TIMER3_InterruptDisable();
#endif
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType Timer3_Write_value(const timer3_t * timer3,uint16 value){

   Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer3){
        ret = E_NOT_OK;
    }else{
        TMR3H = (value)>>8;
        TMR3L =(uint8)(value);
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType Timer3_Read_value(const timer3_t * timer3,uint16 *value){
    Std_ReturnType ret =E_NOT_OK;
    uint8 L_TMR3L =0;
    uint8 L_TMR3H =0;
    
    if ((NULL == timer3)||(NULL == value)){
        ret = E_NOT_OK;
    }else{
        L_TMR3L = TMR3L;
        L_TMR3H = TMR3H;
        *value = (uint16)((TMR3H<<8)+TMR3L);
    }
    return ret;
}

static inline void timer3_mode_select(const timer3_t * timer3){
    if (TIMER3_TIMER_MODE == timer3->timer3_mode){
        TIMER3_TIMER_MODE_ENABLE();
    }else if (TIMER3_COUNTER__MODE== timer3->timer3_mode)
            {
           TIMER3_COUNTER_MODE_ENABLE();
           if (TIMER3_ASYNC_COUNTER_MODE==timer3->timer3_counter_mode)
           {
              TIMER3_ASYNC_COUNTER_MODE_ENABLE(); 
           }else if (TIMER3_SYNC_COUNTER_MODE==timer3->timer3_counter_mode)
           {
               TIMER3_SYNC_COUNTER_MODE_ENABLE();
           }else{/* nothing */}
    }else{/* nothing */}
}
#if TIMER1_INTERRUPT_ENABLE ==1
void TIMER3_ISR(void){
    TIMER3_InterruptFlageClear();
    TMR3H = (timer3_preload)>>8;
    TMR3L =(uint8)(timer3_preload);
    if (TMR3_InterruptHandler){
        TMR3_InterruptHandler();
    }
}
#endif