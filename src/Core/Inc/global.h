#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

// ==========================================
// CÁC TRẠNG THÁI CHO FSM CHÍNH
// ==========================================
#define INIT                1

// Các trạng thái của Mode 1 (automatic)
#define AUTO_RED_GREEN      2
#define AUTO_RED_AMBER      3
#define AUTO_GREEN_RED      4
#define AUTO_AMBER_RED      5

// Các trạng thái của Mode 2, 3, 4 (manual)
#define MAN_RED             12 // Mode 2
#define MAN_AMBER           13 // Mode 3
#define MAN_GREEN           14 // Mode 4

// ==========================================
// TRẠNG THÁI CHO FSM BLINK LED
// ==========================================
#define BLINK_ON            20
#define BLINK_OFF           21

// ==========================================
// CÁC BIẾN TOÀN CỤC (EXTERN)
// ==========================================
// Biến lưu trạng thái hiện tại của hệ thống (2 may 2 bien)
extern int status;
extern int blink_status;

// Các biến lưu thời gian cấu hình thực tế cho các đèn (giây)
extern int time_red;
extern int time_green;
extern int time_amber;

// Các biến đệm dùng trong lúc người dùng đang tăng giá trị (chưa bấm Set)
extern int time_red_temp;
extern int time_green_temp;
extern int time_amber_temp;

// Các biến phục vụ đếm ngược để hiển thị ra LED 7 đoạn
extern int countdown_road1; // Thời gian đếm ngược trục dọc
extern int countdown_road2; // Thời gian đếm ngược trục ngang

#endif /* INC_GLOBAL_H_ */
