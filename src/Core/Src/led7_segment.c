#include "led7_segment.h"
#include "software_timer.h"

int led_buffer[4] = {0, 0, 0, 0};
static int led_index = 0;

// Mảng mã hóa LED 7, Anode chung (active low)
const uint8_t segmentNumber[10] = { //1gfe_dcba (MSB la 1)
    0xC0, // 0
    0xF9, // 1
    0xA4, // 2
    0xB0, // 3
    0x99, // 4
    0x92, // 5
    0x82, // 6
    0xF8, // 7
    0x80, // 8
    0x90  // 9
};

// Hàm xuất mã logic ra 7 chân
void display7SEG(int num) {
    if (num < 0 || num > 9) return;
    uint8_t code = segmentNumber[num];

    // Xuất từng bit của mã Hex ra chân GPIO (1gfe_dcba)
    HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, (code >> 0) & 0x01);
    HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, (code >> 1) & 0x01);
    HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, (code >> 2) & 0x01);
    HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, (code >> 3) & 0x01);
    HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, (code >> 4) & 0x01);
    HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, (code >> 5) & 0x01);
    HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, (code >> 6) & 0x01);
}

// Hàm tắt toàn bộ 4 con LED (Dùng transistor PNP nen 1 la TẮT)
void clearAll7SEG(void) {
    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
}

// Hàm quét LED hiển thị
void update7SEG(int index) {
    clearAll7SEG();                    // Tắt LED trước khi chuyển, tránh Ghosting
    display7SEG(led_buffer[index]);    // Xuất dữ liệu của LED thứ index ra các chân a-g

    // Bật đúng con LED thứ index lên (Xuất mức 0 để kích transistor PNP)
    switch(index) {
        case 0:
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
            break;
        case 1:
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void fsm_7seg_run(void) {
    if (timer_flag[TIMER_7SEG] == 1) {
        setTimer(TIMER_7SEG, 10);
        update7SEG(led_index);

        led_index++;
        if (led_index >= 4) {
            led_index = 0;
        }
    }
}
