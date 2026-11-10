#include "fsm_automatic.h"

// Hàm phụ nạp giá trị đếm ngược vào mảng hiển thị LED 7 đoạn
void update_7seg_buffer_auto() {    // hang chuc lay nguyen, hang dvi lay du
    led_buffer[0] = countdown_road1 / 10;
    led_buffer[1] = countdown_road1 % 10;
    led_buffer[2] = countdown_road2 / 10;
    led_buffer[3] = countdown_road2 % 10;
}

void fsm_automatic_run() {
	// Dang o manual mode thi bo qua
	if (status == MAN_RED || status == MAN_AMBER || status == MAN_GREEN) {
		return;
	}

	if (is_button_pressed(0)) {
		status = MAN_RED;

		time_red_temp = time_red;

		is_button_pressed(1);
		is_button_pressed(2);

		setTimer(TIMER_BLINK, 250);
		setTimer(TIMER_TIMEOUT, 10000);
		turn_off_all_leds();
		return;
	}

    // FSM
    switch (status) {
        case INIT:
            status = AUTO_RED_GREEN;
            countdown_road1 = time_red;
            countdown_road2 = time_green;
            setTimer(TIMER_TRAFFIC, 1000); // Đếm mỗi 1 giây
            turn_on_RED_GREEN();           // ham hanh vi
            update_7seg_buffer_auto();
            break;

        case AUTO_RED_GREEN:
            if (timer_flag[TIMER_TRAFFIC] == 1) {
                setTimer(TIMER_TRAFFIC, 1000);
                countdown_road1--;
                countdown_road2--;

                // Khi đèn Xanh trục 2 đếm hết
                if (countdown_road2 <= 0) {
                    status = AUTO_RED_AMBER;
                    countdown_road2 = time_amber; // Trục 2 chuyển sang Vàng
                    turn_on_RED_AMBER();
                }
                update_7seg_buffer_auto();
            }
            break;

        case AUTO_RED_AMBER:
            if (timer_flag[TIMER_TRAFFIC] == 1) {
                setTimer(TIMER_TRAFFIC, 1000);
                countdown_road1--;
                countdown_road2--;

                // Khi đèn Vàng trục 2 đếm hết
                if (countdown_road2 <= 0) {
                    status = AUTO_GREEN_RED;
                    countdown_road1 = time_green; // Trục 1 chuyển sang Xanh
                    countdown_road2 = time_red;   // Trục 2 chuyển sang Đỏ
                    turn_on_GREEN_RED();
                }
                update_7seg_buffer_auto();
            }
            break;

        case AUTO_GREEN_RED:
            if (timer_flag[TIMER_TRAFFIC] == 1) {
                setTimer(TIMER_TRAFFIC, 1000);
                countdown_road1--;
                countdown_road2--;

                // Khi đèn Xanh trục 1 đếm hết
                if (countdown_road1 <= 0) {
                    status = AUTO_AMBER_RED;
                    countdown_road1 = time_amber; // Trục 1 chuyển sang Vàng
                    turn_on_AMBER_RED();
                }
                update_7seg_buffer_auto();
            }
            break;

        case AUTO_AMBER_RED:
            if (timer_flag[TIMER_TRAFFIC] == 1) {
                setTimer(TIMER_TRAFFIC, 1000);
                countdown_road1--;
                countdown_road2--;

                // Khi đèn Vàng trục 1 đếm hết
                if (countdown_road1 <= 0) {
                    status = AUTO_RED_GREEN;
                    countdown_road1 = time_red;   // Trục 1 chuyển về Đỏ
                    countdown_road2 = time_green; // Trục 2 chuyển về Xanh
                    turn_on_RED_GREEN();
                }
                update_7seg_buffer_auto();
            }
            break;
    }
}
