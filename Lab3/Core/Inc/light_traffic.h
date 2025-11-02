/*
 * light_traffic.h
 *
 *  Created on: Oct 30, 2025
 *      Author: Admin
 */

#ifndef INC_LIGHT_TRAFFIC_H_
#define INC_LIGHT_TRAFFIC_H_

#include "global.h"

/* Private defines -----------------------------------------------------------*/
#define BUTTON1_Pin GPIO_PIN_13
#define BUTTON1_GPIO_Port GPIOC
#define BUTTON2_Pin GPIO_PIN_14
#define BUTTON2_GPIO_Port GPIOC
#define BUTTON3_Pin GPIO_PIN_15
#define BUTTON3_GPIO_Port GPIOC
#define DOT_Pin GPIO_PIN_4
#define DOT_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_6
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_7
#define EN1_GPIO_Port GPIOA
#define SEG0_Pin GPIO_PIN_0
#define SEG0_GPIO_Port GPIOB
#define SEG1_Pin GPIO_PIN_1
#define SEG1_GPIO_Port GPIOB
#define SEG2_Pin GPIO_PIN_2
#define SEG2_GPIO_Port GPIOB
#define LED_GREEN2_Pin GPIO_PIN_10
#define LED_GREEN2_GPIO_Port GPIOB
#define LED_YELLOW2_Pin GPIO_PIN_11
#define LED_YELLOW2_GPIO_Port GPIOB
#define LED_RED2_Pin GPIO_PIN_12
#define LED_RED2_GPIO_Port GPIOB
#define LED_GREEN1_Pin GPIO_PIN_13
#define LED_GREEN1_GPIO_Port GPIOB
#define LED_YELLOW1_Pin GPIO_PIN_14
#define LED_YELLOW1_GPIO_Port GPIOB
#define LED_RED1_Pin GPIO_PIN_15
#define LED_RED1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_8
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_9
#define EN3_GPIO_Port GPIOA
#define SEG3_Pin GPIO_PIN_3
#define SEG3_GPIO_Port GPIOB
#define SEG4_Pin GPIO_PIN_4
#define SEG4_GPIO_Port GPIOB
#define SEG5_Pin GPIO_PIN_5
#define SEG5_GPIO_Port GPIOB
#define SEG6_Pin GPIO_PIN_6
#define SEG6_GPIO_Port GPIOB

void setTrafficLight(int status);
void turnOffTrafficLight();

#endif /* INC_LIGHT_TRAFFIC_H_ */
