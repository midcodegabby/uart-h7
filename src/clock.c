/* 
Author: Gabriel Rodgers <gabrielrodgers4i@gmail.com>
Date: 6/5/2025
*/

#include <stdint.h>

#include "stm32h723xx.h"
#include "clock.h"

void clock_peripherals_init(void) {
    RCC->AHB4ENR |= (1 << 1); //enable GPIOB clk
	RCC->AHB4ENR |= (1 << 4); //enable GPIOE clk
    RCC->AHB4ENR |= (1 << 2); //enable GPIOC clk
	RCC->APB4ENR |= (1 << 1); //enable clock for SYSCFG

    for (volatile uint8_t i = 0; i < 10; i++);
}
