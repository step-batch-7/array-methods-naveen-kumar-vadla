#include <stdio.h>
#include <stdlib.h>
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

ArrayVoid_ptr create_char_ArrayVoid(char *values, int length)
{
  ArrayVoid_ptr array = create_ArrayVoid(length);
  FOR_EACH(0, array->length)
  {
    array->array[i] = &values[i];
  }
  return array;
}

Object square_of_num_void(Object value)
{
  Object result = malloc(sizeof(int));
  *(int *)result = (*(int *)value) * (*(int *)value);
  return result;
}

Object convert_to_lowercase(Object value)
{
  Object result = malloc(sizeof(int));
  *(char *)result = (*(char *)value);
  if (*(char *)result >= 'A' && *(char *)result <= 'Z')
  {
    *(char *)result = *(char *)result + 32;
  }
  return result;
}

void test_map_void(void)
{
  int values[] = {1, 2, 3, 4, 5};
  int expected_values[] = {1, 4, 9, 16, 25};
  char char_values[] = {'a', 'B', 'c', 'D', 'e'};
  char expected_char_values[] = {'a', 'b', 'c', 'd', 'e'};
  ArrayVoid_ptr array, actual, expected;
  Bool status;

  PRINT_STRING("\nmap_void");

  array = create_int_ArrayVoid(values, 0);
  expected = create_int_ArrayVoid(expected_values, 0);
  actual = map_void(array, &square_of_num_void);
  status = assert_ArrayVoid(actual, expected, &assert_integer_void);

  array = create_char_ArrayVoid(char_values, 0);
  expected = create_char_ArrayVoid(expected_char_values, 0);
  actual = map_void(array, &convert_to_lowercase);
  status = status && assert_ArrayVoid(actual, expected, &assert_character_void);
  display_pass_or_fail(status);
  PRINT_STRING("should give empty array for given empty array");

  array = create_int_ArrayVoid(values, 1);
  expected = create_int_ArrayVoid(expected_values, 1);
  actual = map_void(array, &square_of_num_void);
  status = assert_ArrayVoid(actual, expected, &assert_integer_void);

  array = create_char_ArrayVoid(char_values, 1);
  expected = create_char_ArrayVoid(expected_char_values, 1);
  actual = map_void(array, &convert_to_lowercase);
  status = status && assert_ArrayVoid(actual, expected, &assert_character_void);
  display_pass_or_fail(status);
  PRINT_STRING("should map a single value for a given single element array with given mapper");

  array = create_int_ArrayVoid(values, 2);
  expected = create_int_ArrayVoid(expected_values, 2);
  actual = map_void(array, &square_of_num_void);
  status = assert_ArrayVoid(actual, expected, &assert_integer_void);

  array = create_char_ArrayVoid(char_values, 2);
  expected = create_char_ArrayVoid(expected_char_values, 2);
  actual = map_void(array, &convert_to_lowercase);
  status = status && assert_ArrayVoid(actual, expected, &assert_character_void);
  display_pass_or_fail(status);
  PRINT_STRING("should map two values for a given two element array with given mapper");

  array = create_int_ArrayVoid(values, 5);
  expected = create_int_ArrayVoid(expected_values, 5);
  actual = map_void(array, &square_of_num_void);
  status = assert_ArrayVoid(actual, expected, &assert_integer_void);

  array = create_char_ArrayVoid(char_values, 5);
  expected = create_char_ArrayVoid(expected_char_values, 5);
  actual = map_void(array, &convert_to_lowercase);
  status = status && assert_ArrayVoid(actual, expected, &assert_character_void);
  display_pass_or_fail(status);
  PRINT_STRING("should map more values for a given large array with given mapper");
}

Bool is_even_void(Object value)
{
  return (*(int *)value) % 2 == 0;
}

Bool is_vowel_void(Object value)
{
  Object character = convert_to_lowercase(value);
  return *(char *)character == 'a' || *(char *)character == 'e' || *(char *)character == 'i' || *(char *)character == 'o' || *(char *)character == 'u';
}

void test_filter_void(void)
{
  int values[5];
  char char_values[5];
  int expected_values[] = {2, 4};
  char expected_char_values[] = {'a', 'e'};
  ArrayVoid_ptr array, actual, expected;
  Bool status;

  PRINT_STRING("\nfilter_void");

  array = create_int_ArrayVoid(values, 0);
  expected = create_int_ArrayVoid(expected_values, 0);
  actual = filter_void(array, &is_even_void);
  status = assert_ArrayVoid(actual, expected, &assert_integer_void);

  array = create_char_ArrayVoid(char_values, 0);
  expected = create_char_ArrayVoid(expected_char_values, 0);
  actual = filter_void(array, &is_vowel_void);
  status = status && assert_ArrayVoid(actual, expected, &assert_character_void);
  display_pass_or_fail(status);
  PRINT_STRING("should give empty array for given empty array");

  values[0] = 2;
  array = create_int_ArrayVoid(values, 1);
  expected = create_int_ArrayVoid(expected_values, 1);
  actual = filter_void(array, &is_even_void);
  status = assert_ArrayVoid(actual, expected, &assert_integer_void);

  char_values[0] = 'a';
  array = create_char_ArrayVoid(char_values, 1);
  expected = create_char_ArrayVoid(expected_char_values, 1);
  actual = filter_void(array, &is_vowel_void);
  status = status && assert_ArrayVoid(actual, expected, &assert_character_void);
  display_pass_or_fail(status);
  PRINT_STRING("should filter one element when there is only one element in array satisfying given predicate");

  values[0] = 1;
  array = create_int_ArrayVoid(values, 1);
  expected = create_int_ArrayVoid(expected_values, 0);
  actual = filter_void(array, &is_even_void);
  status = assert_ArrayVoid(actual, expected, &assert_integer_void);

  char_values[0] = 'b';
  array = create_char_ArrayVoid(char_values, 1);
  expected = create_char_ArrayVoid(expected_char_values, 0);
  actual = filter_void(array, &is_vowel_void);
  status = status && assert_ArrayVoid(actual, expected, &assert_character_void);
  display_pass_or_fail(status);
  PRINT_STRING("should filter no elements when there is only one element in array not satisfying given predicate");

  values[0] = 1;
  values[1] = 2;
  array = create_int_ArrayVoid(values, 2);
  expected = create_int_ArrayVoid(expected_values, 1);
  actual = filter_void(array, &is_even_void);
  status = assert_ArrayVoid(actual, expected, &assert_integer_void);

  char_values[0] = 'a';
  char_values[1] = 'b';
  array = create_char_ArrayVoid(char_values, 2);
  expected = create_char_ArrayVoid(expected_char_values, 1);
  actual = filter_void(array, &is_vowel_void);
  status = status && assert_ArrayVoid(actual, expected, &assert_character_void);
  display_pass_or_fail(status);
  PRINT_STRING("should filter the elements satisfying given predicate when 2 elements are there in array");

  values[0] = 1;
  values[1] = 2;
  values[2] = 3;
  values[3] = 4;
  values[4] = 5;
  array = create_int_ArrayVoid(values, 5);
  expected = create_int_ArrayVoid(expected_values, 2);
  actual = filter_void(array, &is_even_void);
  status = assert_ArrayVoid(actual, expected, &assert_integer_void);

  char_values[0] = 'a';
  char_values[1] = 'b';
  char_values[2] = 'c';
  char_values[3] = 'd';
  char_values[4] = 'e';
  array = create_char_ArrayVoid(char_values, 5);
  expected = create_char_ArrayVoid(expected_char_values, 2);
  actual = filter_void(array, &is_vowel_void);
  status = status && assert_ArrayVoid(actual, expected, &assert_character_void);
  display_pass_or_fail(status);
  PRINT_STRING("should filter the elements satisfying given predicate when more than 2 elements are there in array");

  values[0] = 1;
  values[1] = 3;
  values[2] = 5;
  array = create_int_ArrayVoid(values, 3);
  expected = create_int_ArrayVoid(expected_values, 0);
  actual = filter_void(array, &is_even_void);
  status = assert_ArrayVoid(actual, expected, &assert_integer_void);

  char_values[0] = 'b';
  char_values[1] = 'c';
  char_values[2] = 'd';
  array = create_char_ArrayVoid(char_values, 3);
  expected = create_char_ArrayVoid(expected_char_values, 0);
  actual = filter_void(array, &is_vowel_void);
  status = status && assert_ArrayVoid(actual, expected, &assert_character_void);
  display_pass_or_fail(status);
  PRINT_STRING("should filter empty when there is no elements satisfying given predicate");
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
