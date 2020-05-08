#include <stdio.h>
#include "../array.h"
#include "assert.h"

Bool assert_Array(Array *actual, Array *expected)
{
  Bool status = actual->length == expected->length;
  FOR_EACH(0, actual->length)
  {
    status = status && (actual->array[i] == expected->array[i]);
  }
  return status;
}
