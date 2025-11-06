/*
 * button.h
 *
 *  Created on: Oct 5, 2023
 *      Author: KAI
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

#define NUM_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 100
#define DURATION_FOR_AUTO_INCREASING 100
#define COMBO_THRESHOLD 500 // 500ms

extern int button1_flag;
extern int combo_flag; //
extern int combo_pair[2];
int isButtonPressed();
void clearButtonFlags();
void getKeyInput();
int isButton1LongPressed();
int isComboPressed();
#endif /* INC_BUTTON_H_ */

