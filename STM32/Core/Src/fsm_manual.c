/*
 * fsm_manual.c
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#include "fsm_manual.h"

//State of fsm
#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4

//Time for fsm
#define RETURN_MODE1 10000

int status_manual = MODE1;

//Return to MODE1
void returnMODE1(void) {
  status_manual = MODE1;
  set_Init();
}

//Increasing time
void inc_time(void) {
  road2_time++;
  if(road2_time > 99) {
    road2_time = 0;
  }
}

void fsm_manual(void) {
  switch(status_manual) {
  case MODE1:
    road1_fsmAuto();
    road2_fsmAuto();
    if(isButtonPressed(mode_BUTTON) == 1) {
      status_manual = MODE2;
      road1_time = MODE2;
      road2_time = red_time;
      restart_fsm();
      setTimer(RETURN_MODE1, mode1_timer);
    }
    break;
  case MODE2:
	blinkLED(RED);
	if(isButtonPressed(mode_BUTTON) == 1) {
	  status_manual = MODE3;
	  road1_time = MODE3;
	  road2_time = yellow_time;
      restart_fsm();
	  setTimer(RETURN_MODE1, mode1_timer);
	}
	if(isButtonPressed(modify_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_MODE1, mode1_timer);
	}
	if(isButtonPressed(set_BUTTON) == 1) {
	  red_time = road2_time;
	  setTimer(RETURN_MODE1, mode1_timer);
	}
	if(isTimerOut(mode1_timer) == 1) {
	  restart_fsm();
	  returnMODE1();
	}
	break;
  case MODE3:
	blinkLED(YELLOW);
	if(isButtonPressed(mode_BUTTON) == 1) {
	  status_manual = MODE4;
	  road1_time = MODE4;
	  road2_time = green_time;
      restart_fsm();
	  setTimer(RETURN_MODE1, mode1_timer);
	}
	if(isButtonPressed(modify_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_MODE1, mode1_timer);
	}
	if(isButtonPressed(set_BUTTON) == 1) {
	  yellow_time = road2_time;
	  setTimer(RETURN_MODE1, mode1_timer);
	}
	if(isTimerOut(mode1_timer) == 1) {
	  restart_fsm();
	  returnMODE1();
	}
	break;
  case MODE4:
	blinkLED(GREEN);
	if(isButtonPressed(mode_BUTTON) == 1) {
	  status_manual = MODE1;
      restart_fsm();
	  set_Init();
	}
	if(isButtonPressed(modify_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_MODE1, mode1_timer);
	}
	if(isButtonPressed(set_BUTTON) == 1) {
	  green_time = road2_time;
	  setTimer(RETURN_MODE1, mode1_timer);
	}
	if(isTimerOut(mode1_timer) == 1) {
	  restart_fsm();
	  returnMODE1();
	}
	break;
  }
}

