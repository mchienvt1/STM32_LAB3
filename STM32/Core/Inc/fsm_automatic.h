/*
 * fsm_automatic.h
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"
#include "output_display.h"
#include "timer_interrupt.h"

void road1_fsmAuto(void);
void road2_fsmAuto(void);

//Set state to INIT
void set_Init(void);


#endif /* INC_FSM_AUTOMATIC_H_ */
