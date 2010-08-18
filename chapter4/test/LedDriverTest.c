#include <cutter.h>
#include "LedDriver.h"

void cut_setup(void)
{
}

void cut_teardown(void)
{
}

void test_LedsOffAfterInitialization(void)
{
  uint16_t virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);
  cut_assert_equal_uint_least16(0, virtualLeds);
}

void test_TurnOnLedOn(void)
{
  uint16_t virtualLeds;
  LedDriver_Create(&virtualLeds);
  LedDriver_TurnOn(1);
  cut_assert_equal_uint_least16(1, virtualLeds);
}
