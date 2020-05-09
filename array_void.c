#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_ArrayVoid_from(int length)
{
  ArrayVoid_ptr array = (ArrayVoid_ptr)malloc(sizeof(ArrayVoid));
  array->array = (Object *)malloc(sizeof(Object) * length);
  array->length = length;
  return array;
}

void display_ArrayVoid(ArrayVoid_ptr array, DisplayData displayer)
{
  FOR_EACH(0, array->length)
  {
    (*displayer)(array->array[i]);
  }
  printf("\n");
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr new_array = create_ArrayVoid_from(src->length);
  FOR_EACH(0, new_array->length)
  {
    new_array->array[i] = (*mapper)(src->array[i]);
  }
  return new_array;
}
