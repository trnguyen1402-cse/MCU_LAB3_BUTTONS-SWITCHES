#include "button.h"

// Mảng lưu trạng thái sau khi debounce
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};

// Hai mảng đệm dùng cho thuật toán so sánh N = 2
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];

// Mảng cờ báo hiệu nút đã được nhấn 1 lần
static int button_flag[NO_OF_BUTTONS] = {0, 0, 0};

// Hàm lấy tín hiệu vật lý của từng nút dựa vào Index
static GPIO_PinState read_button_gpio(int index) {
    switch(index) {
        case 0: return HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
        case 1: return HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);
        case 2: return HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);
        default: return BUTTON_IS_RELEASED;
    }
}

void getKeyInput(void) {
    int isAnyButtonPressed = 0; // Check nút đang bị giữ

    for (int i = 0; i < NO_OF_BUTTONS; i++) {
        // Dịch chuyển bộ đệm
        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
        debounceButtonBuffer1[i] = read_button_gpio(i);

        // Chống dội phím (ổn định trong 20ms)
        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) {
            if (buttonBuffer[i] != debounceButtonBuffer1[i]) {
                buttonBuffer[i] = debounceButtonBuffer1[i];

                // Bật cờ nhấn nút
                if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
                    button_flag[i] = 1;
                }
            }
        }

        // Nếu trang thai nut sau debounce là NHẤN, bật cờ báo cho LED
        if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
            isAnyButtonPressed = 1;
        }
    }

    // Bật/tắt LED signal cho button
    if (isAnyButtonPressed == 1) {
        HAL_GPIO_WritePin(button_signal_led_GPIO_Port, button_signal_led_Pin, GPIO_PIN_RESET);
    } else {
        HAL_GPIO_WritePin(button_signal_led_GPIO_Port, button_signal_led_Pin, GPIO_PIN_SET);
    }
}

// Hàm FSM gọi ra để kiểm tra
int is_button_pressed(int index) {
    if (index < 0 || index >= NO_OF_BUTTONS) return 0;
    if (button_flag[index] == 1) {
        button_flag[index] = 0;
        return 1;
    }
    return 0;
}
