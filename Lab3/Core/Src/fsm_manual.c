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
			led_buffer[0] = manual_led_buffer[0];
			led_buffer[1] = manual_led_buffer[1];
			led_buffer[2] = manual_led_buffer[2];
			led_buffer[3] = manual_led_buffer[3];
			if (isTimerExpire(0)) {
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}
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
			led_buffer[0] = manual_led_buffer[0];
			led_buffer[1] = manual_led_buffer[1];
			led_buffer[2] = manual_led_buffer[2];
			led_buffer[3] = manual_led_buffer[3];
			if (isTimerExpire(0)) {
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}
			setTrafficLight(status);
			if (isButtonPressed(1) == 1) {
				status = MAN_GREEN_RED;
			}
			if (isButtonPressed(0) == 1) { //press button1
				turnOffTrafficLight();
				status = CONFIG_RED; // MODE2 -> MODE3
			}
			break;
		case MAN_GREEN_RED:
			led_buffer[0] = manual_led_buffer[0];
			led_buffer[1] = manual_led_buffer[1];
			led_buffer[2] = manual_led_buffer[2];
			led_buffer[3] = manual_led_buffer[3];
			if (isTimerExpire(0)) {
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}
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
			led_buffer[0] = manual_led_buffer[0];
			led_buffer[1] = manual_led_buffer[1];
			led_buffer[2] = manual_led_buffer[2];
			led_buffer[3] = manual_led_buffer[3];
			if (isTimerExpire(0)) {
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}
			setTrafficLight(status);
			if (isButtonPressed(1) == 1) {
				status = MAN_RED_GREEN;
			}
			if (isButtonPressed(0) == 1) { //press button1
				turnOffTrafficLight();
				status = CONFIG_RED; // MODE2 -> MODE3
			}
			break;
	}
}
