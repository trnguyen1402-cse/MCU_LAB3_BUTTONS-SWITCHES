#include "software_timer.h"

#define TIMER_CYCLE 10    // TICK 10ms

// Khởi tạo cac mảng bằng 0
int timer_flag[MAX_TIMERS] = {0, 0, 0, 0};
int timer_counter[MAX_TIMERS] = {0, 0, 0, 0};

void setTimer(int index, int duration) {
    if (index >= 0 && index < MAX_TIMERS) {
        timer_counter[index] = duration / TIMER_CYCLE;
        timer_flag[index] = 0;
    }
}

void timerRun(void) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (timer_counter[i] > 0) {
            timer_counter[i]--;
            if (timer_counter[i] <= 0) {
                timer_flag[i] = 1;
            }
        }
    }
}
