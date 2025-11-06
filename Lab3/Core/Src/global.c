/*
 * global.c
 *
 *  Created on: Oct 30, 2025
 *      Author: Admin
 */
#include "global.h"

const uint8_t seg_table[10] = {
    0b1000000, // 0
    0b1111001, // 1
    0b0100100, // 2
    0b0110000, // 3
    0b0011001, // 4
    0b0010010, // 5
    0b0000010, // 6
    0b1111000, // 7
    0b0000000, // 8
    0b0010000  // 9
};

int 	index_led 		= 0;
int 	led_buffer[MAX_LED]   = {1, 2, 3, 4};
int 	manual_led_buffer[MAX_LED]   = {1, 1, 4, 7};

int 	T_RED 		= 5;
int 	T_YELLOW 	= 2;
int 	T_GREEN 	= 3;

int     T_RED_modify 	= 0;
int     T_YELLOW_modify = 0;
int     T_GREEN_modify 	= 0;

int 	counterA = 0;   // road A (bắt đầu xanh)
int 	counterB = 0;   // road B (bắt đầu đỏ)
int 	status   = INIT_SYS;

int entered = 0;
