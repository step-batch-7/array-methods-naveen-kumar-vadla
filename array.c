#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array *create_Array_from(int *values, int length)
{
  Array *array = (Array *)malloc(sizeof(Array));
  array->array = (int *)malloc(sizeof(int) * length);
  array->length = length;
  FOR_EACH(0, array->length)
  {
    array->array[i] = values[i];
  }
  return array;
}

void display_Array(Array *array)
{
  FOR_EACH(0, array->length)
  {
    printf("%d ", array->array[i]);
  }
  printf("\n");
}
