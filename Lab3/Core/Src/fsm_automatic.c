/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2025
 *      Author: Admin
 */

#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch (status) {
		case INIT_SYS:
			status = AUTO_RED_GREEN;
			setTimer(0, 250);
			setTimer(1, 1000);
			counterB = T_RED;
			counterA = T_GREEN;
			// T_RED_modify = T_RED;
			// T_GREEN_modify = T_GREEN;
			// T_YELLOW_modify = T_YELLOW;
			break;

		case AUTO_RED_GREEN:
			if (isTimerExpire(0)) {
				update7SEGBuffer(counterA, counterB);
				setTrafficLight(status);
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}
			if (isTimerExpire(1)) {
				--counterA;
				--counterB;
				setTimer(1, 1000);
			}
			if (counterA <= 0) {
				status = AUTO_RED_YELLOW;
				counterA = T_YELLOW;
			}
			if (isButtonPressed(0) == 1) { //press button1
				status = MAN_RED_GREEN; // MODE1 -> MODE2
			}
			break;

		case AUTO_RED_YELLOW:
			if (isTimerExpire(0)) {
				update7SEGBuffer(counterA, counterB);
				setTrafficLight(status);
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}
			if (isTimerExpire(1)) {
				--counterA;
				--counterB;
				setTimer(1, 1000);
			}
			if (counterA <= 0) {
				status = AUTO_GREEN_RED;
				counterB = T_GREEN;
				counterA = T_RED;
			}
			if (isButtonPressed(0) == 1) { //press button1
				status = MAN_RED_GREEN; // MODE1 -> MODE2
			}
			break;

		case AUTO_GREEN_RED:
			if (isTimerExpire(0)) {
				update7SEGBuffer(counterA, counterB);
				setTrafficLight(status);
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}
			if (isTimerExpire(1)) {
				--counterA;
				--counterB;
				setTimer(1, 1000);
			}
			if (counterB <= 0) {
				status = AUTO_YELLOW_RED;
				counterB = T_YELLOW;
			}
			if (isButtonPressed(0) == 1) { //press button1
				status = MAN_RED_GREEN; // MODE1 -> MODE2
			}
			break;

		case AUTO_YELLOW_RED:
			if (isTimerExpire(0)) {
				update7SEGBuffer(counterA, counterB);
				setTrafficLight(status);
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}
			if (isTimerExpire(1)) {
				--counterA;
				--counterB;
				setTimer(1, 1000);
			}
			if (counterB <= 0) {
				status = AUTO_RED_GREEN;
				counterB = T_RED;
				counterA = T_GREEN;
			}
			if (isButtonPressed(0) == 1) { //press button1
				status = MAN_RED_GREEN; // MODE1 -> MODE2
			}
			break;

	}
}
//deadline project: 27/11
