#include <cutter.h>
#include <string.h>
#include <stdio.h>

static char buffer[100];
static const char* expected;
static int length;

static void expect(const char* s)
{
  expected = s;
}

static void given(size_t charsWritten)
{
  cut_assert_equal_size(strlen(expected), charsWritten);
  cut_assert_equal_string(expected, buffer);
  cut_assert_equal_char(0xaa, buffer[strlen(expected) + 1]);
}

void cut_setup(void)
{
  memset(buffer, 0xaa, sizeof(buffer));
  expected = "";
  length = 0;
}

void cut_teardown(void)
{
}

void test_NoFormatOperations(void)
{
  expect("hey");
  given(sprintf(buffer, "hey"));
}

void test_InsertString(void)
{
  expect("Hello, World\n");
  given(sprintf(buffer, "Hello, World\n"));
}
