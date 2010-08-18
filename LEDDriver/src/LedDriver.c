#include "LedDriver.h"

static uint16_t* ledAddress;

enum {
  ALL_LEDS_ON = ~0,
  ALL_LEDS_OFF = ~ALL_LEDS_ON
};

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

void LedDriver_TurnAllOn(void)
{
  *ledAddress = ALL_LEDS_ON;
}
