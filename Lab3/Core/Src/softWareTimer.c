#include "softWareTimer.h"

int timer_counter[MAX_TIMER];
int timer_flag[MAX_TIMER];


void timer_ISR() {
	timerRun();
}
void setTimer(int index, int duration) {
	if (index < 0 || index >= MAX_TIMER) return;

	timer_counter[index] = duration / TICK;
	timer_flag[index]    = 0;
}
int isTimerExpire(int index) {
	if (timer_flag[index] == 1) {
		timer_flag[index] = 0;  // reset flag
		return 1;
	}
	return 0;
}
void timerRun() {
	for (int i = 0; i < MAX_TIMER; ++i) {
		if (timer_counter >= 0) {
			timer_counter[i]--;
			if (timer_counter[i] <= 0) {
				timer_flag[i] = 1;
			}
		}
	}
}
