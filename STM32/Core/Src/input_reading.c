/*
 * input_reading.c
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#include "input_reading.h"

/* Pull-up button */
#define NORMAL_STATE 1
#define PRESSED_STATE 0

//Button Pin
uint16_t BUTTON[button_num] = {MODE_Pin, MODIFY_Pin, SET_Pin};


// Set flag for button
int button_flag[button_num] = {0}; //single press

int KeyReg0[button_num] = {NORMAL_STATE};
int KeyReg1[button_num] = {NORMAL_STATE};
int KeyReg2[button_num] = {NORMAL_STATE};

// Save last state of button
int KeyReg3[button_num] = {NORMAL_STATE};
// Set time for debounce
int TimeOutForKeyPress[button_num] = {200};

// Button reading and debounce
void getKeyInput() {
  for(int i = 0; i < button_num; i++) {
    KeyReg2[i] = KeyReg1[i];
    KeyReg1[i] = KeyReg0[i];
    KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, BUTTON[i]);
    if((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])) {
      if(KeyReg3[i] != KeyReg2[i]) {
    	KeyReg3[i] = KeyReg2[i];
    	if(KeyReg3[i] == PRESSED_STATE) {
    	  TimeOutForKeyPress[i] = 200;
    	  button_flag[i] = 1;
    	}
      }
      else {
        TimeOutForKeyPress[i]--;
        if(TimeOutForKeyPress[i] == 0) {
          if(KeyReg3[i] == PRESSED_STATE) {
            TimeOutForKeyPress[i] = 50;
            button_flag[i] = 1;
          }
        }
      }
    }
  }
}

// Check button is pressed or not
int isButtonPressed(int index) {
  if(checkIndex(index, button_num)) {
    if(button_flag[index] == 1) {
      button_flag[index] = 0;
      return 1;
    }
  }
  return 0;
}

