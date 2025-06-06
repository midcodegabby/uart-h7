//	Author: Gabriel Rodgers <gabrielrodgers4i@gmail.com>
//	Date: 2025-06-02
//	Purpose: To get LD1, LD2, and LD3 on the Nucleo-F446RE to turn on. 

#include <stdint.h>

#include "stm32h723xx.h"
#include "clock.h"
#include "nvic.h"
#include "exti.h"
#include "gpio.h"


//LD1: PB0
//LD2: PE1
//LD3: PB14
//B1: PC13

int main(void) {
	clock_peripherals_init();
	for (volatile int i = 0; i<10; i++);
	gpio_init();
	for (volatile int i = 0; i<10; i++);
	nvic_enable();
	for (volatile int i = 0; i<10; i++);
	exti_init();

	while (1) {
	}

	return 0;
}
