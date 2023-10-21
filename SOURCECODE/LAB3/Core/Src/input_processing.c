/*
 * input_processing.c
 *
 *  Created on: Oct 19, 2023
 *      Author: clong
 */

#include "input_reading.h"
#include "led_display.h"
#include "software_timer.h"

int sevenLEDdisplayBuffer[]={0,1,0,0};
enum MODE{MODE1, MODE2, MODE3, MODE4} ;
enum MODE currMode = MODE1;

void sevenLEDvalueToDisplay(int index,int value){
	switch(index){
	case 0:
		sevenLEDdisplayBuffer[0]=value/10;
		sevenLEDdisplayBuffer[1]=value%10;
		break;
	case 1:
		sevenLEDdisplayBuffer[2]=value/10;
		sevenLEDdisplayBuffer[3]=value%10;
		break;
	default:
		break;
	}
}
void fsm_for_input_processing(void){
	button_reading(0);
	button_reading(1);
	if(timer_flag[1]==1){
		setTimer(1,25);
		switch(currMode){
		case MODE1:
			if(is_button_pressed(0)||is_button_pressed_1s(0)){
				currMode = MODE2;
				sevenLEDvalueToDisplay(0,2);
				OffAllLED();
				ToggleAllRed();
			}
			break;
		case MODE2:
			if(is_button_pressed(0)||is_button_pressed_1s(0)){
				currMode = MODE3;
				sevenLEDvalueToDisplay(0,3);
				OffAllLED();
				ToggleAllYellow();
			}
			break;
		case MODE3:
			if(is_button_pressed(0)||is_button_pressed_1s(0)){
				currMode = MODE4;
				sevenLEDvalueToDisplay(0,4);
				OffAllLED();
				ToggleAllGreen();
			}
			break;
		case MODE4:
			if(is_button_pressed(0)||is_button_pressed_1s(0)){
				currMode = MODE1;
				sevenLEDvalueToDisplay(0,1);
			}
			break;
		}
	}

	TimerInterupt();

}
