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
	gpio_init();
	nvic_enable();
	exti_init();

	while (1) {
	}

	return 0;
}
