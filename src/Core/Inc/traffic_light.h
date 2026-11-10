#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"

// Hàm tắt/bật toàn bộ LED
void turn_off_all_leds(void);
void turn_on_all_leds(void);

// Các hàm bật LED theo pha cho automatic mode
void turn_on_RED_GREEN(void);
void turn_on_RED_AMBER(void);
void turn_on_GREEN_RED(void);
void turn_on_AMBER_RED(void);

// Các hàm bilnk LED cho Manual mode
void toggle_all_RED_leds(void);
void toggle_all_AMBER_leds(void);
void toggle_all_GREEN_leds(void);

#endif /* INC_TRAFFIC_LIGHT_H_ */
