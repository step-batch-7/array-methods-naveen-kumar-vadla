#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "array.h"
#include "array_void.h"

Mapper square_of_num;
Predicate is_even;
Reducer sum;

int square_of_num(int value)
{
  return value * value;
}

Bool is_even(int value)
{
  return value % 2 == 0;
}

int sum(int context, int value)
{
  return context + value;
}

void display_integer(Object number);
void display_integer(Object number)
{
  printf("%d ", *(int *)number);
}

Object square_of_num_void(Object value)
{
  int *result = malloc(sizeof(int));
  *result = (*(int *)value) * (*(int *)value);
  return result;
}

Bool is_even_void(Object value)
{
  return (*(int *)value) % 2 == 0;
}

int main(void);
int main(void)
{
  int length = 5;
  int values[] = {1, 2, 3, 4, 5};
  Array *numbers, *newArray;
  numbers = create_Array_from(values, length);
  PRINT_STRING("Array is :");
  display_Array(numbers);

  PRINT_STRING("------------ Normal Map Filter Reduce ------------");

  newArray = map(numbers, &square_of_num);
  PRINT_STRING("Squares are :");
  display_Array(newArray);

  newArray = filter(numbers, &is_even);
  PRINT_STRING("Even Numbers are :");
  display_Array(newArray);

  int total = reduce(numbers, 0, &sum);
  PRINT_STRING("Sum of Numbers is :");
  printf("%d\n", total);

  PRINT_STRING("------------ Void Map Filter Reduce ------------");

  ArrayVoid_ptr numbers_void, new_void_array;
  numbers_void = create_ArrayVoid_from(length);
  FOR_EACH(0, numbers_void->length)
  {
    numbers_void->array[i] = &values[i];
  }

  new_void_array = map_void(numbers_void, square_of_num_void);
  PRINT_STRING("Squares are :");
  display_ArrayVoid(new_void_array, &display_integer);

  new_void_array = filter_void(numbers_void, is_even_void);
  PRINT_STRING("Even Numbers are :");
  display_ArrayVoid(new_void_array, &display_integer);
}