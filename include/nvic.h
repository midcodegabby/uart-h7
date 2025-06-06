/* 
Author: Gabriel Rodgers <gabrielrodgers4i@gmail.com>
Date: 6/5/2025
*/

#include <stdint.h>

#ifndef _NVIC_H
#define _NVIC_H

void nvic_enable(uint8_t vector_position);
void nvic_disable(uint8_t vector_position);
void nvic_priority(uint8_t vector_position, uint8_t);

#endif /* _NVIC_H */