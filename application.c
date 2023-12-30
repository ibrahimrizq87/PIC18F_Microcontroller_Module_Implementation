/* 
 * File:   application.c
 * Author: Ibrahim BEMO
 *
 * Created on November 1, 2023, 3:51 PM
 */

#include"application.h"
/*
 * 
 */
pin_config_t pin ={
    .port=PORTC_INDEX,
.pin=GPIO_PIN4,
.logic=GPIO_LOW,
.direction=GPIO_DIRECTION_INPUT
};
button_stat_t bt_stat =BUTTON_RELEASED;
button_stat_t bt_stat2 =BUTTON_RELEASED;

logic_t l =GPIO_LOW;
Std_ReturnType ret =E_NOT_OK;
uint8 numbers[9]={0xC0,0xF9,0xA4,0xB0,0x99};
uint8 keyad_number='n';
void ADC_interrupt_ISR(void){
}
adc_config_t adc1 ={
.acquasition_time = ADC_12_TAD,
.channel = ADC_CHANNEL_AN0,

.conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
.voltage_reference =  ADC_VOLTAGE_REFERENCE_DISABLE
};
uint16 adc1_res,adc2_res=500,adc3_res,adc4_res;

int main() {
 
    application_intialize();
    while(1){
        
        ret=ADC_Getconversion(&adc1,ADC_CHANNEL_AN0,&adc1_res);
        ret=ADC_Getconversion(&adc1,ADC_CHANNEL_AN1,&adc2_res);
        ret=ADC_Getconversion(&adc1,ADC_CHANNEL_AN2,&adc3_res);
        ret=ADC_Getconversion(&adc1,ADC_CHANNEL_AN3,&adc4_res);
       
        //keypad_get_value(&keypad,&keyad_number);
        //gpio_pin_read_logic(&pin,&logic);
        /*
        gpio_pin_toggle_logic(&led);
        gpio_pin_toggle_logic(&led2);
        gpio_pin_toggle_logic(&led3);
         
    
        
        gpio_pin_read_logic(&p,&l);
        ret = button_read_status(&button_high,&bt_stat);
        ret = button_read_status(&button_low,&bt_stat2);

        if (bt_stat == BUTTON_PRESSED){
        ret =    led_turn_on(&LED1);
        ret =    led_turn_on(&LED2);
        ret =    led_turn_on(&LED3);
        ret =    led_turn_on(&LED4);
        
        ret =    relay_turn_on(&relay1);
        ret =    relay_turn_off(&relay2);
     
        }
          //__delay_ms(500);
     if (bt_stat2 == BUTTON_PRESSED){
     
         ret =    led_turn_off(&LED1);
        ret =    led_turn_off(&LED2);
        ret =    led_turn_off(&LED3);
        ret =    led_turn_off(&LED4);

        ret =    relay_turn_on(&relay2);
        ret =    relay_turn_off(&relay1);
        
     }
        for (uint8 i =0;i<10;i++){
        //ret = gpio_port_write_logic(segm,numbers[i]);
        ret= seven_segment_write_number(&segment1,i);
            __delay_ms(250);
        }
        //__delay_ms(500);
       
    }
         * */
    }
    return (EXIT_SUCCESS);
}
void application_intialize(void){
    /*
    ret = gpio_pin_intialize(&led);
    ret = gpio_pin_intialize(&led2);
    ret = gpio_pin_intialize(&led3);
    */
    ret = ADC_Init(&adc1);
 
    //ecu_layer_intialize();
}

