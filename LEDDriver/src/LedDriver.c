#include "LedDriver.h"

static uint16_t* ledsAddress;
static uint16_t ledsImage;

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
  ledsAddress = address;
  ledsImage = ALL_LEDS_OFF;
  *ledsAddress = ledsImage;
}

void LedDriver_TurnOn(int ledNumber)
{
  ledsImage |= convertLedNumberToBit(ledNumber);
  *ledsAddress = ledsImage;
}

void LedDriver_TurnOff(int ledNumber)
{
  ledsImage &= ~convertLedNumberToBit(ledNumber);
  *ledsAddress = ledsImage;
}

void LedDriver_TurnAllOn(void)
{
  ledsImage = ALL_LEDS_ON;
  *ledsAddress = ledsImage;
}
