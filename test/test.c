#include <stdio.h>
#include "../array.h"
#include "assert.h"
#include "test.h"

void display_pass_or_fail(Bool status)
{
  status ? printf(PASS) : printf(FAIL);
  status ? PASSING_TESTS++ : FAILING_TESTS++;
}

int square_of_num(int value)
{
  return value * value;
}

void test_map(Array *array, Array *empty_array)
{
  PRINT_STRING("\nmap");
  int expected_values[] = {1, 4, 9, 16, 25};

  Array *expected = create_Array_from(expected_values, 5);
  Array *newArray = map(array, &square_of_num);
  Bool status = assert_Array(newArray, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should map the array with given mapper");

  expected = create_Array_from(expected_values, 0);
  newArray = map(empty_array, &square_of_num);
  status = assert_Array(newArray, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should give empty array for given empty array");
}

int main(void)
{
  int values[] = {1, 2, 3, 4, 5};
  Array *array = create_Array_from(values, 5);
  Array *empty_array = create_Array_from(values, 0);

  test_map(array, empty_array);

  printf(GREEN "\n%d passing" RESET, PASSING_TESTS);
  printf(RED "\n%d failing\n" RESET, FAILING_TESTS);
  return 0;
}