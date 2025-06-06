/* 
Author: Gabriel Rodgers <gabrielrodgers4i@gmail.com>
Date: 6/5/2025
*/

#include <stdint.h>

#include "gpio.h"

void gpio_init(void){
    //button
    GPIOC->MODER &= ~(0x3 << 26); //input mode for PC13
	GPIOC->PUPDR |= (1 << 27); //pull down R for PC13

    //leds
    GPIOB->MODER &= ~(1 << 1); //output mode for PB0
	GPIOB->MODER &= ~(1 << 29); //output mode for PB14
	GPIOE->MODER &= ~(1 << 3); //output mode for PE1
}

void gpio_toggle(char port, uint8_t pin){
    switch(port) {
        case("B"):
            GPIOB->ODR ^= (1 << pin);
            break;
        case("C"):
            GPIOC->ODR ^= (1 << pin); 
            break;
        case("E"):
            GPIOE->ODR ^= (1 << pin); 
            break;
        case(default):
            break; //probably do error msg in the future
    }
}

void gpio_on(char port, uint8_t pin) {
    switch(port) {
        case("B"):
            GPIOB->BSRR |= (1 << pin);
            break;
        case("C"):
            GPIOC->BSRR |= (1 << pin); 
            break;
        case("E"):
            GPIOE->BSRR |= (1 << pin); 
            break;
        case(default):
            break; //probably do error msg in the future
    }
}

void gpio_off(char port, uint8_t pin) {
    switch(port) {
        case("B"):
            GPIOB->BSRR |= (1 << (pin + 16));
            break;
        case("C"):
            GPIOC->BSRR |= (1 << (pin + 16)); 
            break;
        case("E"):
            GPIOE->BSRR |= (1 << (pin + 16)); 
            break;
        case(default):
            break; //probably do error msg in the future
    }
}

