#include "LedDriver.h"

static uint16_t* ledAddress;

void LedDriver_Create(uint16_t* address)
{
  ledAddress = address;
  *ledAddress = 0;
}

void LedDriver_TurnOn(int ledNumber)
{
  *ledAddress |= (1 << (ledNumber - 1));
}

void LedDriver_TurnOff(int ledNumber)
{
  *ledAddress = 0;
}
