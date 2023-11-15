/*
 * timer_interrupt.c
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#include "timer_interrupt.h"

int counter[timer_num] = {0};
int flag[timer_num] = {0};

//Set timer
void setTimer(int duration, int index){
	if(index >= 0 && index < timer_num){
		counter[index] = duration / TIMER_CYCLE;
		flag[index] = 0;
	}
}

//Check timer out
int isTimerOut(int index) {
	if(index >= 0 && index < timer_num) {
		if(flag[index] == 1) {
			flag[index] = 0;
			return 1;
		}
	}
	return 0;
}

//Run timer_interrupt
void timer_run(void) {
  for(int i = 0; i < timer_num; i++) {
	if(counter[i] > 0) {
	  counter[i]--;
	  if(counter[i] <= 0) {
		counter[i] = 0;
		flag[i] = 1;
	  }
	}
  }
}




