#include "global.h"

// trạng thái ban đầu
int status = INIT;
int blink_status = BLINK_ON;

// Thời gian mặc định ban đầu (Đỏ = Xanh + Vàng)
int time_red = 5;
int time_green = 3;
int time_amber = 2;

// Các biến temp ban đầu (bằng thời gian mặc định)
int time_red_temp = 5;
int time_green_temp = 3;
int time_amber_temp = 2;

// Biến đếm ngược
int countdown_road1 = 0;
int countdown_road2 = 0;
