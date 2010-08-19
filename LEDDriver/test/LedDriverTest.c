#include <cutter.h>
#include "LedDriver.h"
#include "RuntimeErrorStub.h"

static uint16_t virtualLeds;

void cut_setup(void)
{
  LedDriver_Create(&virtualLeds);
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

void test_TurnOnLedOne(void)
{
  LedDriver_TurnOn(1);
  cut_assert_equal_uint_least16(1, virtualLeds);
}

void test_TurnOffLedOne(void)
{
  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);
  cut_assert_equal_uint_least16(0, virtualLeds);
}

void test_TurnOnMultipleLeds(void)
{
  LedDriver_TurnOn(9);
  LedDriver_TurnOn(8);
  cut_assert_equal_uint_least16(0x180, virtualLeds);
}

void test_TurnOffAnyLed(void)
{
  LedDriver_TurnAllOn();
  LedDriver_TurnOff(8);
  cut_assert_equal_uint_least16(0xff7f, virtualLeds);
}

void test_AllOn(void)
{
  LedDriver_TurnAllOn();
  cut_assert_equal_uint_least16(0xffff, virtualLeds);
}

void test_LedMemoryIsNotReadable(void)
{
  virtualLeds = 0xffff;
  LedDriver_TurnOn(8);
  cut_assert_equal_uint_least16(0x80, virtualLeds);
}

void test_UpperAndLowerBounds(void)
{
  LedDriver_TurnOn(1);
  LedDriver_TurnOn(16);
  cut_assert_equal_uint_least16(0x8001, virtualLeds);
}

void test_OutOfBoundsTurnOnDoesNoHarm(void)
{
  LedDriver_TurnOn(-1);
  LedDriver_TurnOn(0);
  LedDriver_TurnOn(17);
  LedDriver_TurnOn(3141);
  cut_assert_equal_uint_least16(0, virtualLeds);
}

void test_OutOfBoundsTurnOffDoesNoHarm(void)
{
  LedDriver_TurnAllOn();

  LedDriver_TurnOff(-1);
  LedDriver_TurnOff(0);
  LedDriver_TurnOff(17);
  LedDriver_TurnOff(3141);
  cut_assert_equal_uint_least16(0xffff, virtualLeds);
}

void test_OutOfBoundsProducesRuntimeError(void)
{
  LedDriver_TurnOn(-1);
  cut_assert_equal_string("LED Driver: out-of-bounds LED",
			  RuntimeErrorStub_GetLastError());
}

void test_OutOfBoundsToDo(void)
{
  cut_pend("TODO: what should we do during runtime?");
}

