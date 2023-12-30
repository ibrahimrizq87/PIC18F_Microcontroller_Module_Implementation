
#include"mcal_interrupt_manager.h"


#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
void __interrupt () InterruptManagerHigh(void){}
void __interrupt (low_priority) InterruptManagerLow(void){}
#else

void __interrupt () InteruptManager(void){
    if ((INTERRUPT_ENABLE == INTCONbits.INT0IE)&& (INTERRUPT_OCCUR == INTCONbits.INT0IF)){
    //INT0_ISR();
    }else{}
if ((INTERRUPT_ENABLE == INTCON3bits.INT1IE)&& (INTERRUPT_OCCUR == INTCON3bits.INT1IF)){
    //INT1_ISR();
    }else{}
    if ((INTERRUPT_ENABLE == INTCON3bits.INT2IE)&& (INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
    //INT2_ISR();
    }else{}
    if ((INTERRUPT_ENABLE == PIE1bits.ADIE)&& (INTERRUPT_OCCUR == PIR1bits.ADIF)){
    ADC_ISR();
    }else{}
     if ((INTERRUPT_ENABLE == INTCONbits.TMR0IE)&& (INTERRUPT_OCCUR == INTCONbits.TMR0IF)){
    TIMER0_ISR();
    }else{}
if ((INTERRUPT_ENABLE == PIE1bits.TMR1IE)&& (INTERRUPT_OCCUR == PIR1bits.TMR1IF)){
    TIMER1_ISR();
    }else{}
    if ((INTERRUPT_ENABLE == PIE1bits.TMR2IE)&& (INTERRUPT_OCCUR == PIR1bits.TMR2IF)){
    TIMER2_ISR();
    }else{}
    if ((INTERRUPT_ENABLE == PIE2bits.TMR3IE)&& (INTERRUPT_OCCUR == PIR2bits.TMR3IF)){
    TIMER3_ISR();
    }else{}
}
#endif
