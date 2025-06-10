//	Author: Gabriel Rodgers <gabrielrodgers4i@gmail.com>
//	Date: 2025-06-02
//	Purpose: To get LD1, LD2, and LD3 on the Nucleo-F446RE to turn on. 

#include <stdint.h>

#include "stm32h723xx.h"
#include "clock.h"
#include "nvic.h"
#include "exti.h"
#include "gpio.h"
#include "main.h"
#include "tcnt.h"

//LD1: PB0
//LD2: PE1
//LD3: PB14
//B1: PC13

const GPIO_mode_t led_mode = PWM;
const uint8_t pwm_max = 0xF;
volatile button_state_t button = UNPRESSED;

int main(void) {
	clock_peripherals_init();
	gpio_button_init();
	gpio_led_init(led_mode);
	nvic_enable();
	exti_init();
	timer3_pwm_init();
	timer12_pwm_init();

	while(1) {
		static uint8_t led_brightness = 0;

		if(button == PRESSED) {
			if(led_mode == OUTPUT) {
				gpio_toggle('B', 0);
				gpio_toggle('E', 1);
				gpio_toggle('B', 14);
			}
			else if(led_mode == PWM) {
				led_brightness++;

				timer_pwm_set_duty(3, led_brightness);
				timer_pwm_set_duty(12, led_brightness);
				
				if(led_brightness == pwm_max) {
					led_brightness = 0;
				}
			}
			
			button = UNPRESSED;
		}
	}

	return 0;
}