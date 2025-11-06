/*
 * fsm_manual.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Admin
 */

#include "fsm_manual.h"

void fsm_manual_run() {
	switch (status) {
		case MAN_RED_GREEN:
			if (isTimerExpire(0)) {
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			}
			turnOFF7SEG();
			setTrafficLight(status);
			if (isButtonPressed(1) == 1) {
				status = MAN_RED_YELLOW;
			}
			if (isButtonPressed(0) == 1) { //press button1
				turnOffTrafficLight();
				status = CONFIG_RED; // MODE2 -> MODE3
			}
			break;
		case MAN_RED_YELLOW:
			if (isTimerExpire(0)) {
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			}
			turnOFF7SEG();
			setTrafficLight(status);

			if (!entered) {
				setTimer(2, DELAY_YELLOW);   // timer1 đếm 2 giây
				entered = 1;
			}

			// Sau 2s thì chuyển qua MAN_GREEN_RED
			if (isTimerExpire(2)) {
				status = MAN_GREEN_RED;
				entered = 0;
			}
			if (isButtonPressed(1) == 1) {
				status = MAN_GREEN_RED;
				entered = 0;
			}
			if (isButtonPressed(0) == 1) { //press button1
				entered = 0;
				turnOffTrafficLight();
				status = CONFIG_RED; // MODE2 -> MODE3
			}
			break;
		case MAN_GREEN_RED:
			if (isTimerExpire(0)) {
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			}
			turnOFF7SEG();
			setTrafficLight(status);
			if (isButtonPressed(1) == 1) {
				status = MAN_YELLOW_RED;
			}
			if (isButtonPressed(0) == 1) { //press button1
				turnOffTrafficLight();
				status = CONFIG_RED; // MODE2 -> MODE3
			}
			break;
		case MAN_YELLOW_RED:
			if (isTimerExpire(0)) {
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			}
			turnOFF7SEG();
			setTrafficLight(status);

			if (!entered) {
				setTimer(2, DELAY_YELLOW);   // timer1 đếm 2 giây
				entered = 1;
			}

			// Sau 2s thì chuyển qua MAN_GREEN_RED
			if (isTimerExpire(2)) {
				status = MAN_RED_GREEN;
				entered = 0;
			}
			if (isButtonPressed(1) == 1) {
				entered = 0;
				status = MAN_RED_GREEN;
			}
			if (isButtonPressed(0) == 1) { //press button1
				entered = 0;
				turnOffTrafficLight();
				status = CONFIG_RED; // MODE2 -> MODE3
			}
			break;
	}
}
