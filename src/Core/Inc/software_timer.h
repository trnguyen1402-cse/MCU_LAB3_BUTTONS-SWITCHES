#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

// Số lượng Timer tối đa
#define MAX_TIMERS      4

// ID cho từng Timer
#define TIMER_TRAFFIC   0   // Task đèn giao thông (A1, A2, A3, A4)
#define TIMER_BLINK     1   // Task blink LED 2Hz ở Mode 2,3,4
#define TIMER_7SEG      2   // Task quét 4 con LED 7 đoạn
#define TIMER_TIMEOUT   3   // Task tu dong quay ve automatic mode sau 10s

// Extern mảng cờ và mảng đếm cho các file FSM truy cập
extern int timer_flag[MAX_TIMERS];
extern int timer_counter[MAX_TIMERS];

void setTimer(int index, int duration);
void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
