#include"ecu_layer_init.h"



keypad_t keypad ={
.keypad_rows[0].port=PORTC_INDEX,
.keypad_rows[0].pin=GPIO_PIN0,
.keypad_rows[0].logic=GPIO_LOW,
.keypad_rows[0].direction=GPIO_DIRECTION_OUTPUT,

.keypad_rows[1].port=PORTC_INDEX,
.keypad_rows[1].pin=GPIO_PIN1,
.keypad_rows[1].logic=GPIO_LOW,
.keypad_rows[1].direction=GPIO_DIRECTION_OUTPUT,

.keypad_rows[2].port=PORTC_INDEX,
.keypad_rows[2].pin=GPIO_PIN2,
.keypad_rows[2].logic=GPIO_LOW,
.keypad_rows[2].direction=GPIO_DIRECTION_OUTPUT,

.keypad_rows[3].port=PORTC_INDEX,
.keypad_rows[3].pin=GPIO_PIN3,
.keypad_rows[3].logic=GPIO_LOW,
.keypad_rows[3].direction=GPIO_DIRECTION_OUTPUT,


.keypad_columns[0].port=PORTC_INDEX,
.keypad_columns[0].pin=GPIO_PIN4,
.keypad_columns[0].logic=GPIO_LOW,
.keypad_columns[0].direction=GPIO_DIRECTION_INPUT,

.keypad_columns[1].port=PORTC_INDEX,
.keypad_columns[1].pin=GPIO_PIN5,
.keypad_columns[1].logic=GPIO_LOW,
.keypad_columns[1].direction=GPIO_DIRECTION_INPUT,

.keypad_columns[2].port=PORTC_INDEX,
.keypad_columns[2].pin=GPIO_PIN6,
.keypad_columns[2].logic=GPIO_LOW,
.keypad_columns[2].direction=GPIO_DIRECTION_INPUT,

.keypad_columns[3].port=PORTC_INDEX,
.keypad_columns[3].pin=GPIO_PIN7,
.keypad_columns[3].logic=GPIO_LOW,
.keypad_columns[3].direction=GPIO_DIRECTION_INPUT,

};
/*pin_config_t led={
.port = PORTC_INDEX,
.pin = GPIO_PIN0,
.direction = GPIO_DIRECTION_OUTPUT,
.logic = GPIO_LOW
};

pin_config_t led2={
.port = PORTC_INDEX,
.pin = GPIO_PIN1,
.direction = GPIO_DIRECTION_OUTPUT,
.logic = GPIO_LOW
};

pin_config_t led3={
.port = PORTC_INDEX,
.pin = GPIO_PIN2,
.direction = GPIO_DIRECTION_OUTPUT,
.logic = GPIO_LOW
};
  */
Std_ReturnType ret =E_NOT_OK;
port_index_t segm = PORTC_INDEX;
led_t LED1={
.port = PORTA_INDEX,
.pin = GPIO_PIN0,
.status = GPIO_LOW
};
led_t LED2={
.port = PORTA_INDEX,
.pin = GPIO_PIN1,
.status = GPIO_LOW
};
led_t LED3={
.port = PORTA_INDEX,
.pin = GPIO_PIN2,
.status = GPIO_LOW
};
led_t LED4={
.port = PORTA_INDEX,
.pin = GPIO_PIN3,
.status = GPIO_LOW
};
button_t button_high = {
.connection = BUTTON_ACTIVE_HIGH,
.status =BUTTON_RELEASED,
.pin.direction =GPIO_DIRECTION_INPUT,
.pin.pin=GPIO_PIN4,
.pin.port =PORTA_INDEX,
.pin.logic =GPIO_LOW
};
button_t button_low = {
.connection = BUTTON_ACTIVE_LOW,
.status =BUTTON_RELEASED,
.pin.direction =GPIO_DIRECTION_INPUT,
.pin.pin=GPIO_PIN0,
.pin.port =PORTB_INDEX,
.pin.logic =GPIO_HIGH
};
pin_config_t p ={
.direction =GPIO_DIRECTION_INPUT,
.pin=GPIO_PIN0,
.port =PORTB_INDEX,
.logic =GPIO_HIGH
};

relay_t relay1={
.pin = GPIO_PIN5,
.port =PORTA_INDEX,
.status =RELAY_OFF_STAT
};

relay_t relay2={
.pin = GPIO_PIN1,
.port =PORTB_INDEX,
.status =RELAY_OFF_STAT
};

segment_t segment1={
        
.segment_pins[0].port =PORTC_INDEX,
.segment_pins[0].pin =GPIO_PIN0,
.segment_pins[0].direction =GPIO_DIRECTION_OUTPUT,
.segment_pins[0].logic =GPIO_LOW,

.segment_pins[1].port =PORTC_INDEX,
.segment_pins[1].pin =GPIO_PIN1,
.segment_pins[1].direction =GPIO_DIRECTION_OUTPUT,
.segment_pins[1].logic =GPIO_LOW,

.segment_pins[2].port =PORTC_INDEX,
.segment_pins[2].pin =GPIO_PIN2,
.segment_pins[2].direction =GPIO_DIRECTION_OUTPUT,
.segment_pins[2].logic =GPIO_LOW,

.segment_pins[3].port =PORTC_INDEX,
.segment_pins[3].pin =GPIO_PIN3,
.segment_pins[3].direction =GPIO_DIRECTION_OUTPUT,
.segment_pins[3].logic =GPIO_LOW,

};


void ecu_layer_intialize(void){
    /*
     ret =led_intialize(&LED1);
    ret =led_intialize(&LED2);
    ret =led_intialize(&LED3);
    ret =led_intialize(&LED4);
    
    ret=button_intialize(&button_low);
    ret=button_intialize(&button_high);
    
    ret= relay_intialize(&relay1);
    ret= relay_intialize(&relay2);
    
    ret = gpio_port_intialize_direction(segm,0x00);
    ret = seven_segment_intialize(&segment1);
*/
    ret = keypad_intialize(&keypad);
}