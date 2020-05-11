#include <stdio.h>
#include "../array_void.h"
#include "assert.h"
#include "test_arrayVoid.h"
#include "test.h"

ArrayVoid_ptr create_int_ArrayVoid(int *values, int length)
{
  ArrayVoid_ptr array = create_ArrayVoid(length);
  FOR_EACH(0, array->length)
  {
    array->array[i] = &values[i];
  }
  return array;
}

Object sum_void(Object context, Object value)
{
  *(int *)context = (*(int *)context) + (*(int *)value);
  return context;
}

void test_reduce_void(void)
{
  int values[] = {1, 2, 3, 4, 5};
  int expected_value, context_value;
  Object actual, expected, context;
  ArrayVoid_ptr array;
  Bool status;

  PRINT_STRING("\ntest_reduce_void");

  expected_value = 0;
  expected = &expected_value;
  context_value = 0;
  context = &context_value;
  array = create_int_ArrayVoid(values, 0);
  actual = reduce_void(array, context, &sum_void);
  status = assert_integer_void(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should give initial context for given empty array");

  expected_value = 1;
  expected = &expected_value;
  context_value = 0;
  context = &context_value;
  array = create_int_ArrayVoid(values, 1);
  actual = reduce_void(array, context, &sum_void);
  status = assert_integer_void(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should reduce the array using given reducer for array with one values");

  expected_value = 3;
  expected = &expected_value;
  context_value = 0;
  context = &context_value;
  array = create_int_ArrayVoid(values, 2);
  actual = reduce_void(array, context, &sum_void);
  status = assert_integer_void(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should reduce the array using given reducer for array with 2 values");

  expected_value = 15;
  expected = &expected_value;
  context_value = 0;
  context = &context_value;
  array = create_int_ArrayVoid(values, 5);
  actual = reduce_void(array, context, &sum_void);
  status = assert_integer_void(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should reduce the array using given reducer for array more than 2 values");

  expected_value = 11;
  expected = &expected_value;
  context_value = 10;
  context = &context_value;
  array = create_int_ArrayVoid(values, 1);
  actual = reduce_void(array, context, &sum_void);
  status = assert_integer_void(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should reduce the array using given reducer and using given initial context for array with one values");

  expected_value = 13;
  expected = &expected_value;
  context_value = 10;
  context = &context_value;
  array = create_int_ArrayVoid(values, 2);
  actual = reduce_void(array, context, &sum_void);
  status = assert_integer_void(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should reduce the array using given reducer and using given initial context for array with 2 values");

  expected_value = 25;
  expected = &expected_value;
  context_value = 10;
  context = &context_value;
  array = create_int_ArrayVoid(values, 5);
  actual = reduce_void(array, context, &sum_void);
  status = assert_integer_void(actual, expected);
  display_pass_or_fail(status);
  PRINT_STRING("should reduce the array using given reducer and using given initial context for array more than 2 values");
}
