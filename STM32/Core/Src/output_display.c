/*
 * output_display.c
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#include "output_display.h"

// LED Pin
uint16_t LED[led_num] = {RED1_Pin, YELLOW1_Pin, GREEN1_Pin, RED2_Pin, YELLOW2_Pin, GREEN2_Pin};
// EN Pin
uint16_t EN[en_num] = {EN0_Pin, EN1_Pin, EN2_Pin, EN3_Pin};

uint16_t SEG7[10] = {0x003f, 0x0006, 0x005b, 0x004f, 0x0066,
		             0x006d, 0x007d, 0x0007, 0x007f, 0x006f};

uint16_t offSEG7[10] = {0x0040, 0x0079, 0x0024, 0x0030, 0x0019,
		             0x0012, 0x0002, 0x0078, 0x0000, 0x0010};

//LED 7SEG buffer
int SEG_buffer[4] = {0};


//Turn on LED
void road1_ledOn(int color) {
  if(checkIndex(color, color_num)) {
	HAL_GPIO_WritePin(GPIOA, LED[color], 0);
	for(int i = 0; i < color_num; i++) {
	  if(i != color) {
	    HAL_GPIO_WritePin(GPIOA, LED[i], 1);
	  }
	}
  }
}
void road2_ledOn(int color) {
  if(checkIndex(color, color_num)) {
	HAL_GPIO_WritePin(GPIOA, LED[color_num + color], 0);
	for(int i = 0; i < color_num; i++) {
	  if(i != color) {
	    HAL_GPIO_WritePin(GPIOA, LED[color_num + i], 1);
	  }
	}
  }
}
//Turn off LEDs
void led_Off(void) {
  for(int i = 0; i < led_num; i++) {
    HAL_GPIO_WritePin(GPIOA, LED[i], 1);
  }
}


//turn on ENs pin
void en_On(int index) {
  for(int i = 0; i < en_num; i++) {
    if(i == index) {
      HAL_GPIO_WritePin(GPIOA, EN[i], 0);
    }
    else {
      HAL_GPIO_WritePin(GPIOA, EN[i], 1);
    }
  }
}

//update LED 7SEG buffer
void updateBuffer(void) {
  SEG_buffer[0] = road1_time / 10;
  SEG_buffer[1] = road1_time % 10;
  SEG_buffer[2] = road2_time / 10;
  SEG_buffer[3] = road2_time % 10;
}

//display 7 SEGMENT LED
void display7SEG(int num) {
  if(checkIndex(num, 10)) {
	HAL_GPIO_WritePin(GPIOB, offSEG7[num], SET);
    HAL_GPIO_WritePin(GPIOB, SEG7[num], RESET);
  }
}

