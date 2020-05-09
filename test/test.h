#ifndef __TEST_H
#define __TEST_H

#define PRINT_STRING(string) printf("%s\n", string)

int PASSING_TESTS = 0;
int FAILING_TESTS = 0;

void display_pass_or_fail(Bool status);

Mapper square_of_num;
void test_map(void);

Predicate is_even;
void test_filter(void);

Reducer sum;
void test_reduce(void);

#endif
