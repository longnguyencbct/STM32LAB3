/*
 * led_display.h
 *
 *  Created on: Oct 19, 2023
 *      Author: clong
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

void OnP_A(int num);
void OnP_B(int num);
void OnP_C(int num);
void OnP_D(int num);
void OnP_E(int num);
void OnP_F(int num);
void OnP_G(int num);

void OffP_A(int num);
void OffP_B(int num);
void OffP_C(int num);
void OffP_D(int num);
void OffP_E(int num);
void OffP_F(int num);
void OffP_G(int num);

void display7SEG(int lednum,int num);
void OnEN_7SEG0(int i);
void OffEN_7SEG0(int i);
void OnEN_7SEG1(int i);
void OffEN_7SEG1(int i);
void TurnOffAll7SEG0();
void TurnOffAll7SEG1();
void update7SEG0(int index);
void update7SEG1(int index);
void sevenSegTimerInterupt();



#endif /* INC_LED_DISPLAY_H_ */
