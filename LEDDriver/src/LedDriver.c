#include "LedDriver.h"
#include "RuntimeError.h"
#include <stdbool.h>

static uint16_t* ledsAddress;
static uint16_t ledsImage;

enum {
  ALL_LEDS_ON = ~0,
  ALL_LEDS_OFF = ~ALL_LEDS_ON
};

enum {
  FIRST_LED = 1,
  LAST_LED  = 16,
};

static uint16_t convertLedNumberToBit(int ledNumber)
{
  return (1 << (ledNumber - 1));
}

static void updateHardware(void)
{
  *ledsAddress = ledsImage;
}

static bool isLedOutOfBounds(int ledNumber)
{
  if ((ledNumber < FIRST_LED) || (ledNumber > LAST_LED)) {
    RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
    return true;
  } else {
    return false;
  }
}

static void setLedImageBit(int ledNumber)
{
  ledsImage |= convertLedNumberToBit(ledNumber);
}

static void clearLedImageBit(int ledNumber)
{
  ledsImage &= ~convertLedNumberToBit(ledNumber);
}

void LedDriver_Create(uint16_t* address)
{
  ledsAddress = address;
  ledsImage = ALL_LEDS_OFF;
  updateHardware();
}

void LedDriver_TurnOn(int ledNumber)
{
  if (isLedOutOfBounds(ledNumber)) {
    return;
  }

  setLedImageBit(ledNumber);
  updateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
  if (isLedOutOfBounds(ledNumber)) {
    return;
  }

  clearLedImageBit(ledNumber);
  updateHardware();
}

void LedDriver_TurnAllOn(void)
{
  ledsImage = ALL_LEDS_ON;
  updateHardware();
}
