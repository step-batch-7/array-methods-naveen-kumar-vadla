#include <stdio.h>
#include "../array.h"
#include "assert.h"
#include "test_array.h"
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
  test_map();
  test_filter();
  test_reduce();

  printf(GREEN "\n%d passing" RESET, PASSING_TESTS);
  printf(RED "\n%d failing\n" RESET, FAILING_TESTS);
  return 0;
}