/*
 * input_processing.h
 *
 *  Created on: Oct 19, 2023
 *      Author: clong
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

extern int sevenLEDdisplayBuffer[];
void fsm_for_input_processing(void);
void sevenLEDvalueToDisplay(int index,int value);
#endif /* INC_INPUT_PROCESSING_H_ */
