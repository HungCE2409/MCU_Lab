/*
 * main.h
 *
 *  Created on: Sep 21, 2025
 *      Author: Admin
 */

#ifndef SRC_SOFTWARETIMER_H_
#define SRC_SOFTWARETIMER_H_

#define MAX_TIMER 20 // so luong timer
#define TICK 10

extern int timer_counter[MAX_TIMER];
extern int timer_flag[MAX_TIMER];


void timer_ISR();
void setTimer(int, int);
int isTimerExpire(int);
void timerRun();

#endif /* SRC_SOFTWARETIMER_H_ */
