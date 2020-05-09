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

void test_map(void)
{
  int values[] = {1, 2, 3, 4, 5};
  int expected_values[] = {1, 4, 9, 16, 25};
  Array *array, *actual, *expected;
  Bool status;

  PRINT_STRING("\nmap");

  array = create_Array_from(values, 5);
  expected = create_Array_from(expected_values, 5);
  actual = map(array, &square_of_num);
  status = assert_Array(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should map the array with given mapper");

  array = create_Array_from(values, 0);
  expected = create_Array_from(expected_values, 0);
  actual = map(array, &square_of_num);
  status = assert_Array(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should give empty array for given empty array");
}

Bool is_even(int value)
{
  return value % 2 == 0;
}

void test_filter(void)
{
  int values[] = {1, 2, 3, 4, 5};
  int expected_values[] = {2, 4};
  Array *array, *actual, *expected;
  Bool status;

  PRINT_STRING("\nfilter");

  array = create_Array_from(values, 5);
  expected = create_Array_from(expected_values, 2);
  actual = filter(array, &is_even);
  status = assert_Array(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should filter the array using given predicate");

  array = create_Array_from(values, 0);
  expected = create_Array_from(expected_values, 0);
  actual = filter(array, &is_even);
  status = assert_Array(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should give empty array for given empty array");
}

int sum(int context, int value)
{
  return context + value;
}

void test_reduce(void)
{
  int values[] = {1, 2, 3, 4, 5};
  int actual, expected;
  Array *array;
  Bool status;

  PRINT_STRING("\nreduce");

  expected = 15;
  array = create_Array_from(values, 5);
  actual = reduce(array, 0, &sum);
  status = assert_integer(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should reduce the array using given reducer and context");

  expected = 0;
  array = create_Array_from(values, 0);
  actual = reduce(array, 0, &sum);
  status = assert_integer(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should give context for given empty array");
}

int main(void)
{
  test_map();
  test_filter();
  test_reduce();

  printf(GREEN "\n%d passing" RESET, PASSING_TESTS);
  printf(RED "\n%d failing\n" RESET, FAILING_TESTS);
  return 0;
}