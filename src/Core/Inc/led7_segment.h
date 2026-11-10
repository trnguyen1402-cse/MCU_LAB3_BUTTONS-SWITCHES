#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "main.h"

// Mảng giá trị cần hiển thị của 4 con LED (các file khác nạp số vào đây)
extern int led_buffer[4];

void display7SEG(int num);
void update7SEG(int index);
void fsm_7seg_run(void); // fsm goi trong while(1)

#endif /* INC_LED7_SEGMENT_H_ */
