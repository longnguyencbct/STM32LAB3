/*
 * input_reading.c
 *
 *  Created on: Oct 19, 2023
 *      Author: clong
 */

#include "main.h"
//we aim to work with more than one buttons
#define N0_OF_BUTTONS 				       3
//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   100
#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET
//the buffer that the final result is stored after
//debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
//we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];
//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];
void button_reading(int index){
	switch(index){

	case 0:
		debounceButtonBuffer2[0] =debounceButtonBuffer1[0];
		debounceButtonBuffer1[0] = HAL_GPIO_ReadPin(Button0_GPIO_Port, Button0_Pin);
		if(debounceButtonBuffer1[0] == debounceButtonBuffer2[0])
			buttonBuffer[0] = debounceButtonBuffer1[0];
			if(buttonBuffer[0] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress1s[0] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[0]++;
				} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
					flagForButtonPress1s[0] = 1;
					//todo
				}
			} else {
				counterForButtonPress1s[0] = 0;
				flagForButtonPress1s[0] = 0;
			}
		break;
	case 1:
		debounceButtonBuffer2[1] =debounceButtonBuffer1[1];
		debounceButtonBuffer1[1] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
		if(debounceButtonBuffer1[1] == debounceButtonBuffer2[1])
			buttonBuffer[1] = debounceButtonBuffer1[1];
			if(buttonBuffer[1] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress1s[1] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[1]++;
				} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
					flagForButtonPress1s[1] = 1;
					//todo
				}
			} else {
				counterForButtonPress1s[1] = 0;
				flagForButtonPress1s[1] = 0;
			}
		break;
	case 2:
		debounceButtonBuffer2[2] =debounceButtonBuffer1[2];
		debounceButtonBuffer1[2] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
		if(debounceButtonBuffer1[2] == debounceButtonBuffer2[2])
			buttonBuffer[2] = debounceButtonBuffer1[2];
			if(buttonBuffer[2] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress1s[2] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[2]++;
				} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
					flagForButtonPress1s[2] = 1;
					//todo
				}
			} else {
				counterForButtonPress1s[2] = 0;
				flagForButtonPress1s[2] = 0;
			}
		break;
	default:
		break;
	}

}
unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xff;
	return (flagForButtonPress1s[index] == 1);
}

