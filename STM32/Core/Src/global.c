/*
 * global.c
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#include "global.h"

int road1_time = 0;
int road2_time = 0;
int red_time = 5;
int yellow_time = 2;
int green_time = 3;

//Check valid index
int checkIndex(int index, int max) {
  if(index >= 0 && index < max) {
	return 1;
  }
  return 0;
}

