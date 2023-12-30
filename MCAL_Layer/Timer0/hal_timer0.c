#include"hal_timer0.h"


#if TIMER0_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
static void (*TMR0_InterruptHandler) (void) = NULL;
#endif
static uint16 timer0_preload =0;
static inline void timer0_prescaler_config(const timer0_t * timer0);
static inline void timer0_mode_select(const timer0_t * timer0);
static inline void timer0_register_size_config(const timer0_t * timer0);

Std_ReturnType Timer0_Init(const timer0_t * timer0){
    Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer0){
        ret = E_NOT_OK;
    }else{
        TIMER0_MODULE_DISABLE();
        timer0_prescaler_config(timer0);
        timer0_mode_select(timer0);
        timer0_register_size_config(timer0);
        TMR0H = (timer0->timer0_preload_value)>>8;
        TMR0L =(uint8)(timer0->timer0_preload_value);
    #if TIMER0_INTERRUPT_ENABLE ==INTERRUPT_ENABLE

 TIMER0_InterruptEnable();
 TIMER0_InterruptFlageClear();
 TMR0_InterruptHandler=timer0->TIMER0_InterruptHandler;
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
 INTERRUPT_PriorityLevelEnable();
if (timer0->prioprity == INTERRUPT_HIGH_PRIORITY){
    INTERRUPT_GlobalInterruptHighEnable();
    TIMER0_HighPrioritySet();
    
}else if (timer0->prioprity == INTERRUPT_LOW_PRIORITY){
    INTERRUPT_GlobalInterruptLowEnable();
TIMER0_LowPrioritySet();
}else{/*nothing*/}
#else
  INTERRUPT_GlobalInterruptEnable();
 INTERRUPT_PeripheralInterruptEnable();
#endif
#endif
 
        TIMER0_MODULE_ENABLE();
        
    ret = E_OK;
    }
    return ret;
}
Std_ReturnType Timer0_DeInit(const timer0_t * timer0){
    Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer0){
        ret = E_NOT_OK;
    }else{
        TIMER0_MODULE_DISABLE();
#if TIMER0_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
    TIMER0_InterruptDisable();
#endif
    ret = E_OK;
    }
    return ret;
}
Std_ReturnType Timer0_Write_value(const timer0_t * timer0,uint16 value){
    Std_ReturnType ret =E_NOT_OK;
    if (NULL == timer0){
        ret = E_NOT_OK;
    }else{
        TMR0H = (value)>>8;
        TMR0L =(uint8)(value);
    }
    return ret;
}
Std_ReturnType Timer0_Read_value(const timer0_t * timer0,uint16 *value){
    Std_ReturnType ret =E_NOT_OK;
    uint8 L_TMR0L =0;
    uint8 L_TMR0H =0;
    
    if ((NULL == timer0)||(NULL == value)){
        ret = E_NOT_OK;
    }else{
        L_TMR0L = TMR0L;
        L_TMR0H = TMR0H;
        *value = (uint16)((TMR0H<<8)+TMR0L);
    }
    return ret;
}


#if TIMER0_INTERRUPT_ENABLE ==1
void TIMER0_ISR(void){
    TIMER0_InterruptFlageClear();
    
    TMR0H = (timer0_preload)>>8;
    TMR0L =(uint8)(timer0_preload);
    if (TMR0_InterruptHandler){
        TMR0_InterruptHandler();
    }
}
#endif

static inline void timer0_prescaler_config(const timer0_t * timer0)
{
    if (TIMER0_PRESCALER_ENABLE_CFG == timer0->prescaler_enable)
    {
        TIMER0_PRESCALER_ENABLE();
        T0CONbits.T0PS = timer0->prescaler_value;
    }else if (TIMER0_PRESCALER_DISABLE_CFG== timer0->prescaler_enable)
    {
         TIMER0_PRESCALER_DISABLE();
    }else{/* nothing */}
}


static inline void timer0_mode_select(const timer0_t * timer0){
    if (TIMER0_TIMER_MODE == timer0->timer0_mode){
        TIMER0_TIMER_MODE_ENABLE();
    }else if (TIMER0_COUNTER__MODE== timer0->timer0_mode)
            {
           TIMER0_COUNTER_MODE_ENABLE();
           if (TIMER0_FALLING_EDGE_CFG==timer0->counter_edge)
           {
              TIMER0_FALLING_EDGE_ENABLE(); 
           }else if (TIMER0_RISING_EDGE_CFG==timer0->counter_edge)
           {
               TIMER0_RISING_EDGE_ENABLE();
           }else{/* nothing */}
    }else{/* nothing */}
}

static inline void timer0_register_size_config(const timer0_t * timer0){
    if (TIMER0_8BIT_REGISTER_MODE == timer0->timer0_register_size){
        TIMER0_8BIT_REGISTER_MODE_ENABLE();
    }else if (TIMER0_16BIT_REGISTER_MODE== timer0->timer0_mode)
    {
        TIMER0_16BIT_REGISTER_MODE_ENABLE();
    }else{/* nothing */}
}

