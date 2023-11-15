/*
 * fsm_display.h
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#ifndef INC_FSM_DISPLAY_H_
#define INC_FSM_DISPLAY_H_

#include "global.h"
#include "output_display.h"
#include "timer_interrupt.h"

//Set restart 7SEG display
void restart_fsm(void);

//Display 7SEG LED
void fsm_display(void);

//Blinky LED have 'color'
void blinkLED(int color);

#endif /* INC_FSM_DISPLAY_H_ */
