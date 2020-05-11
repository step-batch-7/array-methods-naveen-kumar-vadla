#include <stdio.h>
#include "assert.h"

Bool assert_integer(int actual, int expected)
{
  return actual == expected;
}

Bool assert_integer_void(Object actual, Object expected)
{
  return *(int *)actual == *(int *)expected;
}

Bool assert_character_void(Object actual, Object expected)
{
  return *(char *)actual == *(char *)expected;
}

Bool assert_Array(Array *actual, Array *expected)
{
  Bool status = assert_integer(actual->length, expected->length);
  FOR_EACH(0, actual->length)
  {
    status = status && (actual->array[i] == expected->array[i]);
  }
  return status;
}

Bool assert_ArrayVoid(ArrayVoid_ptr actual, ArrayVoid_ptr expected, Bool asserter(Object, Object))
{
  Bool status = assert_integer(actual->length, expected->length);
  FOR_EACH(0, actual->length)
  {
    status = status && (*asserter)(actual->array[i], expected->array[i]);
  }
  return status;
}