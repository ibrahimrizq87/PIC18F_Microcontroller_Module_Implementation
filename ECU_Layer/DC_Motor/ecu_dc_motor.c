#include"ecu_dc_motor.h"



Std_ReturnType dc_motor_intialize(const dc_motor_t *motor){
Std_ReturnType ret = E_OK;
if (motor == NULL){
ret =E_NOT_OK;
}else{
    pin_config_t pin1 ={
    .pin =motor->dc_motor[0].motor_pin,
    .port=motor->dc_motor[0].motor_port,
    .logic = motor->dc_motor[0].motor_status,
    .direction = GPIO_DIRECTION_OUTPUT};
    
    pin_config_t pin2 ={
    .pin =motor->dc_motor[1].motor_pin,
    .port=motor->dc_motor[1].motor_port,
    .logic = motor->dc_motor[1].motor_status,
    .direction = GPIO_DIRECTION_OUTPUT};
    gpio_pin_intialize(&pin1);
    gpio_pin_intialize(&pin2);
}
return ret;
}
Std_ReturnType dc_motor_move_right(const dc_motor_t *motor){
Std_ReturnType ret = E_OK;
if (motor == NULL){
ret =E_NOT_OK;
}else{
    pin_config_t pin1 ={
    .pin =motor->dc_motor[0].motor_pin,
    .port=motor->dc_motor[0].motor_port,
    .logic = motor->dc_motor[0].motor_status,
    .direction = GPIO_DIRECTION_OUTPUT};
    
    pin_config_t pin2 ={
    .pin =motor->dc_motor[1].motor_pin,
    .port=motor->dc_motor[1].motor_port,
    .logic = motor->dc_motor[1].motor_status,
    .direction = GPIO_DIRECTION_OUTPUT};
    gpio_pin_write_logic(&pin1,GPIO_HIGH);
    gpio_pin_write_logic(&pin2,GPIO_LOW);

}
return ret;
}
Std_ReturnType dc_motor_move_left(const dc_motor_t *motor){
Std_ReturnType ret = E_OK;
if (motor == NULL){
ret =E_NOT_OK;
}else{
    pin_config_t pin1 ={
    .pin =motor->dc_motor[0].motor_pin,
    .port=motor->dc_motor[0].motor_port,
    .logic = motor->dc_motor[0].motor_status,
    .direction = GPIO_DIRECTION_OUTPUT};
    
    pin_config_t pin2 ={
    .pin =motor->dc_motor[1].motor_pin,
    .port=motor->dc_motor[1].motor_port,
    .logic = motor->dc_motor[1].motor_status,
    .direction = GPIO_DIRECTION_OUTPUT};
    gpio_pin_write_logic(&pin1,GPIO_LOW);
    gpio_pin_write_logic(&pin2,GPIO_HIGH);
}
return ret;
}
Std_ReturnType dc_motor_stop(const dc_motor_t *motor){
Std_ReturnType ret = E_OK;
if (motor == NULL){
ret =E_NOT_OK;
}else{
    pin_config_t pin1 ={
    .pin =motor->dc_motor[0].motor_pin,
    .port=motor->dc_motor[0].motor_port,
    .logic = motor->dc_motor[0].motor_status,
    .direction = GPIO_DIRECTION_OUTPUT};
    
    pin_config_t pin2 ={
    .pin =motor->dc_motor[1].motor_pin,
    .port=motor->dc_motor[1].motor_port,
    .logic = motor->dc_motor[1].motor_status,
    .direction = GPIO_DIRECTION_OUTPUT};
    gpio_pin_write_logic(&pin1,GPIO_LOW);
    gpio_pin_write_logic(&pin2,GPIO_LOW);
}
return ret;
}

