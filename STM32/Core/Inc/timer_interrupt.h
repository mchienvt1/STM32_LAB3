/*
 * timer_interrupt.h
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */
#include "global.h"

#ifndef INC_TIMER_INTERRUPT_H_
#define INC_TIMER_INTERRUPT_H_

#define en_timer 0
#define road1_timer 1
#define road2_timer 2
#define clock_timer1 3
#define clock_timer2 4
#define mode1_timer 5
#define blink_timer 6

void setTimer(int duration, int index);
int isTimerOut(int index);
void timer_run(void);

#endif /* INC_TIMER_INTERRUPT_H_ */
