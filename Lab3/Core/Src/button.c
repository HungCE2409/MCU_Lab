#include "button.h"

#define NUM_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 100

int KeyReg0[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimeOutForKeyPress[NUM_OF_BUTTONS] = {DURATION_FOR_AUTO_INCREASING, DURATION_FOR_AUTO_INCREASING, DURATION_FOR_AUTO_INCREASING};
int button_flag[NUM_OF_BUTTONS] = {0, 0, 0};

GPIO_TypeDef* BUTTON_PORT[NUM_OF_BUTTONS] = {BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port};
uint16_t BUTTON_PIN[NUM_OF_BUTTONS] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

//------------------------
int isButtonPressed(int index){
	if(button_flag[index]){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

//------------------------
void getKeyInput(){
	for(int i = 0; i < NUM_OF_BUTTONS; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON_PORT[i], BUTTON_PIN[i]);

		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg3[i] == PRESSED_STATE){
					TimeOutForKeyPress[i] = DURATION_FOR_AUTO_INCREASING;
					button_flag[i] = 1;
				}
			} else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
					TimeOutForKeyPress[i] = DURATION_FOR_AUTO_INCREASING;
					if (KeyReg3[i] == PRESSED_STATE){
						button_flag[i] = 1;
					}
				}
			}
		}
	}
}
