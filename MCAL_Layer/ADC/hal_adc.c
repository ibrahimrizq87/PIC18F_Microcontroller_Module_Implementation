#include"hal_adc.h"

static void (*ADC_InterruptHandler)(void) = NULL;
static inline void adc_input_channel_port_config(adc_channel_select_t channel);
static inline void select_result_frormat(const adc_config_t *adc);
static inline void convertion_voltage_reference(const adc_config_t *adc);



Std_ReturnType ADC_Init(const adc_config_t *adc){
Std_ReturnType ret=E_NOT_OK;
if(NULL == adc){
}else{
    ADC_CONVERSION_DISALBLE();
ADCON2bits.ACQT = adc->acquasition_time;
ADCON2bits.ADCS=adc->conversion_clock;
ADCON0bits.CHS=adc->channel;
adc_input_channel_port_config(adc->channel);

#if ADC_INTERRUPT_ENABLE ==1
ADC_InterruptEnable();
ADC_InterruptFlageClear();

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE


if (adc->prioprity == INTERRUPT_HIGH_PRIORITY){
    ADC_HighPrioritySet();
}else if (adc->prioprity == INTERRUPT_LOW_PRIORITY){
ADC_LowPrioritySet();
}else{/*nothing*/}
#else
 INTERRUPT_GlobalInterruptEnable();
 INTERRUPT_PeripheralInterruptEnable();
#endif

 ADC_InterruptHandler = adc->ADC_InterruptHandler;
#endif
select_result_frormat(adc);
convertion_voltage_reference(adc);
    
     ADC_CONVERSION_ENALBLE();
ret=E_OK;
}
return ret;
}

Std_ReturnType ADC_DeInit(const adc_config_t *adc){
Std_ReturnType ret=E_NOT_OK;
if(NULL == adc){
}else{

   ADC_CONVERSION_DISALBLE();
#if ADC_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
ADC_InterruptDisable();   
#endif
ret=E_OK;
}
return ret;
}

Std_ReturnType ADC_Select_channel(const adc_config_t *adc,adc_channel_select_t channel){
Std_ReturnType ret=E_NOT_OK;
if(NULL == adc){
}else{
ADCON0bits.CHS=channel;
adc_input_channel_port_config(channel);

ret=E_OK;
}
return ret;
}
Std_ReturnType ADC_start_conversion(){
Std_ReturnType ret=E_NOT_OK;
ADC_START_CONVERSION();
//ADCON0bits.GODONE = 1;
ret=E_OK;
return ret;
}

Std_ReturnType ADC_IsConversionDone(const adc_config_t *adc,uint8 *conversion_status){
Std_ReturnType ret=E_NOT_OK;
if((NULL == adc)||(NULL==conversion_status)){
}else{
*conversion_status= (uint8)(!(ADCON0bits.GO_nDONE));
ret=E_OK;
}
return ret;
}




Std_ReturnType ADC_Getconversion_result(const adc_config_t *adc,adc_result *conversion_result){
Std_ReturnType ret=E_NOT_OK;
if((NULL == adc)||(NULL==conversion_result)){
   ret=E_NOT_OK;
}else{
if (adc->result_format == ADC_RIGHT_FORMAT)
    {
    *conversion_result = (adc_result) ((ADRESH <<8) + ADRESL);
    }else if(adc->result_format == ADC_LEFT_FORMAT){
      *conversion_result = (adc_result) (((ADRESH <<8) + ADRESL)>>6);
    }else{
        *conversion_result = (adc_result) ((ADRESH <<8) + ADRESL);
    }

ret=E_OK;
}
return ret;
}
Std_ReturnType ADC_Getconversion(const adc_config_t *adc,adc_channel_select_t channel,adc_result *conversion_result){
Std_ReturnType ret=E_NOT_OK;
//uint8 conversion_status=0;
if((NULL == adc)||(NULL==conversion_result)){
}else{
    
    ret = ADC_Select_channel(adc,channel);
    ret = ADC_start_conversion(adc);
    while(ADCON0bits.GO_nDONE);
    ADC_Getconversion_result(adc,conversion_result);
   
}
return ret;
}

Std_ReturnType ADC_Getconversion_Interrupt(const adc_config_t *adc,adc_channel_select_t channel){
    Std_ReturnType ret=E_NOT_OK;
//uint8 conversion_status=0;
if(NULL == adc){
}else{
    
    ret = ADC_Select_channel(adc,channel);
    ret = ADC_start_conversion(adc); 
  
   /*
    * ADC_IsConversionDone(adc,&conversion_status);
    *  if (ADC_CONVERSTION_COMPLETED == conversion_status){
  ADC_Getconversion_result(adc,conversion_result);
    }else{
   ret=E_NOT_OK;
    }*/
}
return ret;
}


static inline void adc_input_channel_port_config(adc_channel_select_t channel){
    switch (channel){
        case ADC_CHANNEL_AN0 : SET_BIT(TRISA, _TRISA_RA0_POSN ); 
        break;
        case ADC_CHANNEL_AN1 : SET_BIT(TRISA, _TRISA_RA1_POSN ); 
        break;
        case ADC_CHANNEL_AN2 : SET_BIT(TRISA, _TRISA_RA2_POSN ); 
        break;
        case ADC_CHANNEL_AN3 : SET_BIT(TRISA, _TRISA_RA3_POSN ); 
        break;
        case ADC_CHANNEL_AN4 : SET_BIT(TRISA, _TRISA_RA4_POSN ); 
        break;
        case ADC_CHANNEL_AN5 : SET_BIT(TRISA, _TRISA_RA5_POSN ); 
        break;
        case ADC_CHANNEL_AN6 : SET_BIT(TRISE,_TRISE_RE0_POSN  ); 
        break;
        case ADC_CHANNEL_AN7 : SET_BIT(TRISE,_TRISE_RE1_POSN ); 
        break;
        case ADC_CHANNEL_AN8 : SET_BIT(TRISE, _TRISE_RE2_POSN ); 
        break;
        case ADC_CHANNEL_AN9 : SET_BIT(TRISB, _TRISB_RB3_POSN ); 
        break;
        case ADC_CHANNEL_AN10 : SET_BIT(TRISB, _TRISB_RB1_POSN ); 
        break;
        case ADC_CHANNEL_AN11 : SET_BIT(TRISB, _TRISB_RB4_POSN ); 
        break;
        case ADC_CHANNEL_AN12 : SET_BIT(TRISB, _TRISB_RB0_POSN ); 
        break;
        
    }
}


static inline void select_result_frormat(const adc_config_t *adc){
    if (adc->result_format == ADC_RIGHT_FORMAT)
    {
        ADC_RESULT_RIGHT_FORMAT();
    }else if(adc->result_format == ADC_LEFT_FORMAT){
    ADC_RESULT_LEFT_FORMAT();
    }else{
        ADC_RESULT_RIGHT_FORMAT();
    }
}

static inline void convertion_voltage_reference(const adc_config_t *adc){
    if (adc->voltage_reference == ADC_VOLTAGE_REFERENCE_ENABLE)
    {
       ADC_ENABLE_VOLTAGE_REFERENCE();
    }else if(adc->voltage_reference == ADC_VOLTAGE_REFERENCE_DISABLE){
           ADC_DISABLE_VOLTAGE_REFERENCE();
    }else{
          ADC_DISABLE_VOLTAGE_REFERENCE();
    }
}
#if ADC_INTERRUPT_ENABLE ==1
void ADC_ISR(void){
    ADC_InterruptFlageClear();
    if (ADC_InterruptHandler){
    ADC_InterruptHandler();
    }
}
#endif