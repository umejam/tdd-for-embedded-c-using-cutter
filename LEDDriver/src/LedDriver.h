#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

void LedDriver_Create(uint16_t* address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnOff(int ledNumber);
bool LedDriver_IsOn(int ledNumber);

#endif
