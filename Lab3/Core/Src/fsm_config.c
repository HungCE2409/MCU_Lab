/*
 * fsm_config.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Admin
 */

#include "fsm_config.h"

void fsm_config_run() {
	switch (status) {
		case CONFIG_RED:
			led_buffer[0] = T_RED_modify / 10;
			led_buffer[1] = T_RED_modify % 10;
			led_buffer[2] = 0;
			led_buffer[3] = 1;
			if (isTimerExpire(0)) {
				setTrafficLight(status);
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}

			if (isButtonPressed(2) == 1) { //press button2 and button3 to save
				if (T_RED_modify > 50) { // minimum red light duration is 20 seconds
				  break;
				}
				T_RED = T_RED_modify;
				T_GREEN = T_RED - T_YELLOW;
				counterB = T_RED;
				counterA = T_GREEN;
			}
			if (isButtonPressed(0) == 1) { //press button2, change led
			    status = CONFIG_GREEN;
				turnOffTrafficLight();
			}
			if (isButtonPressed(1) == 1) { //press button3, modify time
			    T_RED_modify++;
			    if (T_RED_modify >= 100) T_RED_modify = 0;
			}
			break;

		case CONFIG_GREEN:
			led_buffer[0] = T_GREEN_modify / 10;
			led_buffer[1] = T_GREEN_modify % 10;
			led_buffer[2] = 0;
			led_buffer[3] = 2;
			if (isTimerExpire(0)) {
				setTrafficLight(status);
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}

			if (isButtonPressed(2) == 1) { //press button2 and button3 to save
				if (T_GREEN_modify > 49) { // minimum red light duration is 20 seconds
				  break;
				}
				T_GREEN = T_GREEN_modify;
				T_RED = T_GREEN + T_YELLOW;
				counterB = T_RED;
				counterA = T_GREEN;
			}
			if (isButtonPressed(0) == 1) { //press button2, change led
			    status = CONFIG_YELLOW;
				turnOffTrafficLight();
			}
			if (isButtonPressed(1) == 1) { //press button3, modify time
			    T_GREEN_modify++;
			    if (T_GREEN_modify >= 100) T_GREEN_modify = 0;
			}
			break;
		case CONFIG_YELLOW:
			led_buffer[0] = T_YELLOW_modify / 10;
			led_buffer[1] = T_YELLOW_modify % 10;
			led_buffer[2] = 0;
			led_buffer[3] = 3;
			if (isTimerExpire(0)) {
				setTrafficLight(status);
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				update7SEG(index_led++);
				if (index_led >= MAX_LED) index_led = 0;
				setTimer(0, 250); // reset timer 0.25s
			}

			if (isButtonPressed(2) == 1) { //press button2 and button3 to save
				status = INIT_SYS; // MODE3 -> MODE1
				if (T_YELLOW_modify > 5) {
				  break;
				}
				T_YELLOW = T_YELLOW_modify;
				T_RED = T_GREEN + T_YELLOW;
				counterB = T_RED;
				counterA = T_GREEN;
			}
			if (isButtonPressed(0) == 1) { //press button2, change led
			    status = AUTO_RED_GREEN;
				turnOffTrafficLight();
			}
			if (isButtonPressed(1) == 1) { //press button3, modify time
			    T_YELLOW_modify++;
			    if (T_YELLOW_modify >= 100) T_YELLOW_modify = 0;
			}
			break;
	}
}
