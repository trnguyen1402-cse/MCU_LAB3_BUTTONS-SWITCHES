#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NO_OF_BUTTONS 3

// input pull-up
#define BUTTON_IS_PRESSED       GPIO_PIN_RESET
#define BUTTON_IS_RELEASED      GPIO_PIN_SET

void getKeyInput(void);
int is_button_pressed(int index);

#endif /* INC_BUTTON_H_ */
