#include "LedDriver.h"

static uint16_t* ledAddress;

static uint16_t convertLedNumberToBit(int ledNumber)
{
  return (1 << (ledNumber - 1));
}

void LedDriver_Create(uint16_t* address)
{
  ledAddress = address;
  *ledAddress = 0;
}

void LedDriver_TurnOn(int ledNumber)
{
  *ledAddress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber)
{
  *ledAddress = 0;
}
