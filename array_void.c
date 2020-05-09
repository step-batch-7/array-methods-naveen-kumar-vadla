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

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object filtered_values[src->length];
  int filters_count = 0;
  FOR_EACH(0, src->length)
  {
    Bool result = (*predicate)(src->array[i]);
    if (result)
    {
      filtered_values[filters_count] = src->array[i];
      filters_count++;
    }
  }
  ArrayVoid_ptr new_array = create_ArrayVoid_from(filters_count);
  FOR_EACH(0, new_array->length)
  {
    new_array->array[i] = filtered_values[i];
  }
  return new_array;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  FOR_EACH(0, src->length)
  {
    init = (*reducer)(init, src->array[i]);
  }
  return init;
}
