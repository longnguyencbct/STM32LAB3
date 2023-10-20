/*
 * input_processing.c
 *
 *  Created on: Oct 19, 2023
 *      Author: clong
 */

#include "input_reading.h"

int sevenLEDvalueBuffer[]={1,0};
int sevenLEDdisplayBuffer[]={0,1,0,0};
enum MODE{MODE1, MODE2, MODE3, MODE4} ;
enum MODE currMode = MODE1;
void fsm_for_input_processing(void){
	switch(currMode){
	case MODE1:
		if(is_button_pressed(0)){
			currMode = MODE2;
			sevenLEDvalueBuffer[0]=2;
			sevenLEDvalueToDisplay(0,2);
		}
		break;
	case MODE2:
		if(is_button_pressed(0)){
			currMode = MODE3;
			sevenLEDvalueBuffer[0]=3;
			sevenLEDvalueToDisplay(0,3);
		}
		break;
	case MODE3:
		if(is_button_pressed(0)){
			currMode = MODE4;
			sevenLEDvalueBuffer[0]=4;
			sevenLEDvalueToDisplay(0,4);
		}
		break;

	case MODE4:
		if(is_button_pressed(0)){
			currMode = MODE1;
			sevenLEDvalueBuffer[0]=1;
			sevenLEDvalueToDisplay(0,1);
		}
		break;
	}
}
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
