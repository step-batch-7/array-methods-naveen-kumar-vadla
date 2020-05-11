#include <stdio.h>
#include "../array_void.h"
#include "assert.h"
#include "test_array.h"
#include "test_arrayVoid.h"
#include "test.h"

int PASSING_TESTS = 0;
int FAILING_TESTS = 0;

void display_pass_or_fail(Bool status)
{
  status ? printf(PASS) : printf(FAIL);
  status ? PASSING_TESTS++ : FAILING_TESTS++;
}

int main(void)
{
  printf("\n------------------------------------------------ Normal Map Filter Reduce ------------------------------------------------\n");

  test_map();
  test_filter();
  test_reduce();

  printf("\n------------------------------------------------ Void Map Filter Reduce ------------------------------------------------\n");

  test_map_void();
  test_reduce_void();

  printf(GREEN "\n%d passing" RESET, PASSING_TESTS);
  printf(RED "\n%d failing\n" RESET, FAILING_TESTS);
  return 0;
}