#ifndef __TEST_ARRAY_H
#define __TEST_ARRAY_H

#define PRINT_STRING(string) printf("%s\n", string)

Mapper square_of_num;
void test_map(void);

Predicate is_even;
void test_filter(void);

Reducer sum;
void test_reduce(void);

#endif
