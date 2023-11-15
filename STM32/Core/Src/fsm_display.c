/*
 * fsm_display.c
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#include "global.h"
#include "timer_interrupt.h"
#include "output_display.h"
#include "input_reading.h"
#include "fsm_display.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"


//Set state for 7SEG fsm display
#define INIT 0
#define EN0 1
#define EN1 2
#define EN2 3
#define EN3 4

//Set state for blink fsm LED
#define LED_ON 1
#define LED_OFF 2

#define PIECE_TIME 250
#define BLINK_TIME 500

int status_display = INIT;
int status_blink = INIT;

//Restart 7SEG display
void restart_fsm(void) {
  status_display = INIT;
}

//Display 7SEG LED
void fsm_display(void) {
  updateBuffer();
  switch(status_display) {
  case INIT:
	setTimer(PIECE_TIME, en_timer);
    status_display = EN0;
    break;
  case EN0:
    en_On(EN0 - 1);
    display7SEG(SEG_buffer[EN0 - 1]);
    if(isTimerOut(en_timer) == 1) {
      status_display = EN1;
      setTimer(PIECE_TIME, en_timer);
    }
    break;
  case EN1:
	en_On(EN1 - 1);
    display7SEG(SEG_buffer[EN1 - 1]);
	if(isTimerOut(en_timer) == 1) {
	  status_display = EN2;
	  setTimer(PIECE_TIME, en_timer);
	}
	break;
  case EN2:
	en_On(EN2 - 1);
    display7SEG(SEG_buffer[EN2 - 1]);
	if(isTimerOut(en_timer) == 1) {
	  status_display = EN3;
	  setTimer(PIECE_TIME, en_timer);
	}
	break;
  case EN3:
	en_On(EN3 - 1);
    display7SEG(SEG_buffer[EN3 - 1]);
	if(isTimerOut(en_timer) == 1) {
	  status_display = EN0;
	  setTimer(PIECE_TIME, en_timer);
	}
	break;
  }
}

//Blinky LED
void blinkLED(int color) {
  switch(status_blink) {
  case INIT:
    status_blink = LED_ON;
    setTimer(BLINK_TIME, blink_timer);
    break;
  case LED_ON:
	road1_ledOn(color);
	road2_ledOn(color);
	if(isTimerOut(blink_timer) == 1) {
	  status_blink = LED_OFF;
	  setTimer(BLINK_TIME, blink_timer);
	}
	break;
  case LED_OFF:
	led_Off;
	if(isTimerOut(blink_timer) == 1) {
	  status_blink = LED_ON;
	  setTimer(BLINK_TIME, blink_timer);
	}
	break;
  }
}

