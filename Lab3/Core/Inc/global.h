/*
 * global.h
 *
 *  Created on: Oct 30, 2025
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "softwareTimer.h"
#include "button.h"
#include "light_traffic.h"

extern const uint8_t seg_table[10];
#define MAX_LED 4 // number LED 7 SEG

extern int 	index_led;
extern int 	led_buffer[MAX_LED];
extern int 	manual_led_buffer[MAX_LED];

#define INIT_SYS          0
#define AUTO_RED_GREEN    1
#define AUTO_RED_YELLOW   2
#define AUTO_GREEN_RED    3
#define AUTO_YELLOW_RED   4
#define MAN_RED_GREEN     5
#define MAN_RED_YELLOW    6
#define MAN_GREEN_RED     7
#define MAN_YELLOW_RED    8
#define CONFIG_RED        9
#define CONFIG_GREEN      10
#define CONFIG_YELLOW     11

extern int 	T_RED;
extern int 	T_YELLOW;
extern int 	T_GREEN;

extern int  T_RED_modify;
extern int  T_YELLOW_modify;
extern int  T_GREEN_modify;

extern int 	counterA;    // road A (bắt đầu xanh)
extern int 	counterB;   // road B (bắt đầu đỏ)
extern int 	status;

extern int entered;
#endif /* INC_GLOBAL_H_ */
