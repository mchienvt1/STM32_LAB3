/*
 * output_display.h
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

#include "main.h"
#include "stdint.h"
#include "global.h"

extern int SEG_buffer[4];

//Turn on LED
void road1_ledOn(int color);
void road2_ledOn(int color);

//Turn off LEDs
void led_Off(void);

//turn on EN pin
void en_On(int index);

//update 7SEG buffer
void updateBuffer(void);

//display 7 SEG LED
void display7SEG(int num);

#endif /* INC_OUTPUT_DISPLAY_H_ */
