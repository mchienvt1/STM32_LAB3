/*
 * global.h
 *
 *  Created on: Nov 15, 2023
 *      Author: lmchi
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

extern int road1_time;
extern int road2_time;
extern int red_time;
extern int yellow_time;
extern int green_time;

#define timer_num 7 //Number of timer
#define TIMER_CYCLE 10 //Timer Cycle = 10ms
#define TIME_UNIT 1000 // Time Unit = 1s

#define led_num 6 // Number of traffic led
#define en_num 4 // Number of 7SEG led
#define button_num 3

#define color_num 3
#define RED 0
#define YELLOW 1
#define GREEN 2

int checkIndex(int index, int MAX);

#endif /* INC_GLOBAL_H_ */

