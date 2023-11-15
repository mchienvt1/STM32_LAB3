/*
 * fsm_automatic.c
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#include "fsm_automatic.h"

//State of fsm
#define INIT 0
#define RED_STATE 1
#define YELLOW_STATE 2
#define GREEN_STATE 3

//Clock counter
#define CLOCK_TIME 1000

int status_auto_road1 = INIT;
int status_auto_road2 = INIT;

/* Function -----*/
void road1_fsmAuto(void) {
  if(isTimerOut(clock_timer1)) {
    road1_time--;
    setTimer(CLOCK_TIME, clock_timer1);
  }
  switch(status_auto_road1) {
  case INIT:
    status_auto_road1 = RED_STATE;
    road1_time = red_time;
    setTimer(red_time * TIME_UNIT, road1_timer);
    setTimer(CLOCK_TIME, clock_timer1);
    break;
  case RED_STATE:
	road1_ledOn(RED);
	if(isTimerOut(road1_timer) == 1) {
	  status_auto_road1 = GREEN_STATE;
	  road1_time = green_time;
	  setTimer(green_time * TIME_UNIT, road1_timer);
	  setTimer(CLOCK_TIME, clock_timer1);
	}
    break;
  case YELLOW_STATE:
	road1_ledOn(YELLOW);
	if(isTimerOut(road1_timer) == 1) {
	  status_auto_road1 = RED_STATE;
	  road1_time = red_time;
	  setTimer(red_time * TIME_UNIT, road1_timer);
	  setTimer(CLOCK_TIME, clock_timer1);
	}
    break;
  case GREEN_STATE:
	road1_ledOn(GREEN);
	if(isTimerOut(road1_timer) == 1) {
	  status_auto_road1 = YELLOW_STATE;
	  road1_time = yellow_time;
	  setTimer(yellow_time * TIME_UNIT, road1_timer);
	  setTimer(CLOCK_TIME, clock_timer1);
	}
    break;
  }
}
void road2_fsmAuto(void) {
  if(isTimerOut(clock_timer2)) {
    road2_time--;
    setTimer(CLOCK_TIME, clock_timer2);
  }
  switch(status_auto_road2) {
  case INIT:
    status_auto_road2 = GREEN_STATE;
    road2_time = green_time;
    setTimer(green_time * TIME_UNIT, road2_timer);
    setTimer(CLOCK_TIME, clock_timer2);
    break;
  case RED_STATE:
	road2_ledOn(RED);
	if(isTimerOut(road2_timer) == 1) {
	  status_auto_road2 = GREEN_STATE;
	  road2_time = green_time;
	  setTimer(green_time * TIME_UNIT, road2_timer);
	  setTimer(CLOCK_TIME, clock_timer2);
	}
    break;
  case YELLOW_STATE:
	road2_ledOn(YELLOW);
	if(isTimerOut(road2_timer) == 1) {
	  status_auto_road2 = RED_STATE;
	  road2_time = red_time;
	  setTimer(red_time * TIME_UNIT, road2_timer);
	  setTimer(CLOCK_TIME, clock_timer2);
	}
    break;
  case GREEN_STATE:
	road2_ledOn(GREEN);
	if(isTimerOut(road2_timer) == 1) {
	  status_auto_road2 = YELLOW_STATE;
	  road2_time = yellow_time;
	  setTimer(yellow_time * TIME_UNIT, road2_timer);
	  setTimer(CLOCK_TIME, clock_timer2);
	}
    break;
  }
}
//Set state to INIT
void set_Init(void) {
  status_auto_road1 = INIT;
  status_auto_road2 = INIT;
}

