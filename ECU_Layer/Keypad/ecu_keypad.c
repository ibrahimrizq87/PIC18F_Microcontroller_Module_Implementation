#include"ecu_keypad.h"


static const uint8 keypad_char [ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS]={
                                   {'7','8','9','/'},
                                   {'4','5','6','*'},
                                   {'1','2','3','-'},
                                   {'#','0','=','+'},
};
#define _XTAL_FREQ 4000000UL

Std_ReturnType keypad_intialize(const keypad_t *keypad){
Std_ReturnType ret =E_OK;

if (keypad == NULL){
    ret =E_NOT_OK;
}else{
for (uint8 count = 0;count<ECU_KEYPAD_ROWS;count++){
    ret = gpio_pin_intialize(&(keypad->keypad_columns[count]));
}
for (uint8 count = 0;count<ECU_KEYPAD_COLUMNS;count++){
    ret = gpio_pin_intialize_direction(&(keypad->keypad_rows[count]));
}
}
return ret;
}
Std_ReturnType keypad_get_value(const keypad_t *keypad,uint8 *value){
Std_ReturnType ret =E_OK;
uint8 l_row_counter=0;
uint8 row_counter=0;
uint8 column_counter=0; 
logic_t logic = GPIO_LOW;
if ((keypad == NULL)||(value == NULL)){
   ret =E_NOT_OK;
}else{
    for (l_row_counter=0;l_row_counter<ECU_KEYPAD_ROWS;l_row_counter++){
        for (row_counter=0;row_counter<ECU_KEYPAD_ROWS;row_counter++)
        {
            ret = gpio_pin_write_logic(&(keypad->keypad_rows[row_counter]),GPIO_LOW);
        }
       // *value = l_row_counter;
        __delay_ms(500);
        
        ret = gpio_pin_write_logic(&(keypad->keypad_rows[l_row_counter]),GPIO_HIGH);
        for (column_counter=0;column_counter<ECU_KEYPAD_COLUMNS;column_counter++){
            ret = gpio_pin_read_logic(&(keypad->keypad_columns[column_counter]),&logic);
            if (logic == GPIO_HIGH)
            {
                *value =keypad_char[l_row_counter][column_counter];
            }
    }
    }
}
return ret;
}