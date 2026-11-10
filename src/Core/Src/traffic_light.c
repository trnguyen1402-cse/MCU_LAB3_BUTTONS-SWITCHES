#include "traffic_light.h"

// AUTOMATIC
void turn_off_all_leds(void) {
    HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(AMB_1_GPIO_Port, AMB_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GRN_1_GPIO_Port, GRN_1_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(AMB_2_GPIO_Port, AMB_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GRN_2_GPIO_Port, GRN_2_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(RED_3_GPIO_Port, RED_3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(AMB_3_GPIO_Port, AMB_3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GRN_3_GPIO_Port, GRN_3_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(RED_4_GPIO_Port, RED_4_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(AMB_4_GPIO_Port, AMB_4_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GRN_4_GPIO_Port, GRN_4_Pin, GPIO_PIN_SET);
}

void turn_on_all_leds(void) {
    HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AMB_1_GPIO_Port, AMB_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GRN_1_GPIO_Port, GRN_1_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AMB_2_GPIO_Port, AMB_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GRN_2_GPIO_Port, GRN_2_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(RED_3_GPIO_Port, RED_3_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AMB_3_GPIO_Port, AMB_3_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GRN_3_GPIO_Port, GRN_3_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(RED_4_GPIO_Port, RED_4_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AMB_4_GPIO_Port, AMB_4_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GRN_4_GPIO_Port, GRN_4_Pin, GPIO_PIN_RESET);
}

void turn_on_RED_GREEN(void) {
    turn_off_all_leds();
    HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RED_3_GPIO_Port, RED_3_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GRN_2_GPIO_Port, GRN_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GRN_4_GPIO_Port, GRN_4_Pin, GPIO_PIN_RESET);
}

void turn_on_RED_AMBER(void) {
    turn_off_all_leds();
    HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RED_3_GPIO_Port, RED_3_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(AMB_2_GPIO_Port, AMB_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AMB_4_GPIO_Port, AMB_4_Pin, GPIO_PIN_RESET);
}

void turn_on_GREEN_RED(void) {
    turn_off_all_leds();
    HAL_GPIO_WritePin(GRN_1_GPIO_Port, GRN_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GRN_3_GPIO_Port, GRN_3_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RED_4_GPIO_Port, RED_4_Pin, GPIO_PIN_RESET);
}

void turn_on_AMBER_RED(void) {
    turn_off_all_leds();
    HAL_GPIO_WritePin(AMB_1_GPIO_Port, AMB_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(AMB_3_GPIO_Port, AMB_3_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RED_4_GPIO_Port, RED_4_Pin, GPIO_PIN_RESET);
}

// MANUAL
void toggle_all_RED_leds(void) {
    HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);
    HAL_GPIO_TogglePin(RED_2_GPIO_Port, RED_2_Pin);
    HAL_GPIO_TogglePin(RED_3_GPIO_Port, RED_3_Pin);
    HAL_GPIO_TogglePin(RED_4_GPIO_Port, RED_4_Pin);
}

void toggle_all_AMBER_leds(void) {
    HAL_GPIO_TogglePin(AMB_1_GPIO_Port, AMB_1_Pin);
    HAL_GPIO_TogglePin(AMB_2_GPIO_Port, AMB_2_Pin);
    HAL_GPIO_TogglePin(AMB_3_GPIO_Port, AMB_3_Pin);
    HAL_GPIO_TogglePin(AMB_4_GPIO_Port, AMB_4_Pin);
}

void toggle_all_GREEN_leds(void) {
    HAL_GPIO_TogglePin(GRN_1_GPIO_Port, GRN_1_Pin);
    HAL_GPIO_TogglePin(GRN_2_GPIO_Port, GRN_2_Pin);
    HAL_GPIO_TogglePin(GRN_3_GPIO_Port, GRN_3_Pin);
    HAL_GPIO_TogglePin(GRN_4_GPIO_Port, GRN_4_Pin);
}
