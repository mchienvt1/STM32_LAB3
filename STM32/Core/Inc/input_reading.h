/*
 * input_reading.h
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "global.h"
#include "stdint.h"
#include "main.h"

#define mode_BUTTON 0
#define modify_BUTTON 1
#define set_BUTTON 2

// Button reading and debounce
void getKeyInput();

// Check button is pressed or not
int isButtonPressed(int index);

#endif /* INC_INPUT_READING_H_ */

