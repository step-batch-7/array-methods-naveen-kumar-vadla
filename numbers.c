#include <stdio.h>
#include "array.h"

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

int main(void);
int main(void)
{
  int values[] = {1, 2, 3, 4, 5};
  Array *numbers = create_Array_from(values, 5);
  PRINT_STRING("Array is :");
  display_Array(numbers);

  Array *newArray = map(numbers, &square_of_num);
  PRINT_STRING("Squares are :");
  display_Array(newArray);

  newArray = filter(numbers, &is_even);
  PRINT_STRING("Even Numbers are :");
  display_Array(newArray);

  int total = reduce(numbers, 0, &sum);
  PRINT_STRING("Sum of Numbers is :");
  printf("%d\n", total);
}