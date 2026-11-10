#include "fsm_manual.h"

// Cac bien de luu tru trang thai dung truoc khi vao che do cai dat
static int original_red = 0;
static int original_amber = 0;
static int original_green = 0;

// Ham phu: LED 0,1 hien thi Thoi gian - LED 2,3 hien thi Mode
void update_7seg_buffer_manual(int mode, int time_val) {
    led_buffer[0] = time_val / 10;
    led_buffer[1] = time_val % 10;
    led_buffer[2] = mode / 10;
    led_buffer[3] = mode % 10;
}

void fsm_manual_run() {
    // Neu dang khong o cac che do Manual, bo qua ham nay
    if (status != MAN_RED && status != MAN_AMBER && status != MAN_GREEN) {
        // Lien tuc sao luu trang thai
        original_red = time_red;
        original_amber = time_amber;
        original_green = time_green;
        return;
    }

    // Het 10s khong thao tac, tu dong ve Automatic Mode
    // va khoi phuc trang thai dung truoc do neu dang chinh dang do
    if (timer_flag[TIMER_TIMEOUT] == 1) {
        time_red = original_red;
        time_amber = original_amber;
        time_green = original_green;

        status = INIT;
        is_button_pressed(1);
        is_button_pressed(2);
        turn_off_all_leds();
        return;
    }

    // FSM
    switch (status) {
        case MAN_RED:   // MODE 2: CHINH DO
            update_7seg_buffer_manual(2, time_red_temp);

            if (timer_flag[TIMER_BLINK] == 1) {
                setTimer(TIMER_BLINK, 250);
                toggle_all_RED_leds();
            }

            if (is_button_pressed(1)) {
                time_red_temp++;
                if (time_red_temp > 99) time_red_temp = 0;
                setTimer(TIMER_TIMEOUT, 10000);
            }

            if (is_button_pressed(2)) {
                time_red = time_red_temp; // Tam thoi luu gia tri
                setTimer(TIMER_TIMEOUT, 10000);
            }

            if (is_button_pressed(0)) {
                status = MAN_AMBER;
                time_amber_temp = time_amber; // Lay gia tri hien tai lam goc

                is_button_pressed(1);
                is_button_pressed(2);
                setTimer(TIMER_TIMEOUT, 10000);
                turn_off_all_leds();
            }
            break;

        case MAN_AMBER:   // MODE 3: CHINH VANG
            update_7seg_buffer_manual(3, time_amber_temp);

            if (timer_flag[TIMER_BLINK] == 1) {
                setTimer(TIMER_BLINK, 250);
                toggle_all_AMBER_leds();
            }

            if (is_button_pressed(1)) {
                time_amber_temp++;
                if (time_amber_temp > 99) time_amber_temp = 0;
                setTimer(TIMER_TIMEOUT, 10000);
            }

            if (is_button_pressed(2)) {
                time_amber = time_amber_temp;
                setTimer(TIMER_TIMEOUT, 10000);
            }

            if (is_button_pressed(0)) {
                status = MAN_GREEN;
                time_green_temp = time_green; // Lay gia tri hien tai lam goc

                is_button_pressed(1);
                is_button_pressed(2);
                setTimer(TIMER_TIMEOUT, 10000);
                turn_off_all_leds();
            }
            break;

        case MAN_GREEN:   // MODE 4: CHINH XANH
            update_7seg_buffer_manual(4, time_green_temp);

            if (timer_flag[TIMER_BLINK] == 1) {
                setTimer(TIMER_BLINK, 250);
                toggle_all_GREEN_leds();
            }

            if (is_button_pressed(1)) {
                time_green_temp++;
                if (time_green_temp > 99) time_green_temp = 0;
                setTimer(TIMER_TIMEOUT, 10000);
            }

            if (is_button_pressed(2)) {
                time_green = time_green_temp;
                setTimer(TIMER_TIMEOUT, 10000);
            }

            // Kiem tra hop le va ket thuc
            if (is_button_pressed(0)) {
                // Kiem tra logic: Do = Xanh + Vang
                if (time_red != (time_green + time_amber)) {
                    // CAU HINH SAI: Khoi phuc lai cac gia tri goc truoc do
                    time_red = original_red;
                    time_amber = original_amber;
                    time_green = original_green;
                }

                status = INIT;       // Reset chu ky ve trang thai ban dau

                is_button_pressed(1);
                is_button_pressed(2);
                setTimer(TIMER_TIMEOUT, 10000);
                turn_off_all_leds();
            }
            break;
    }
}
