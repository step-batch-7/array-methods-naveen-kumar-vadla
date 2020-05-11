#ifndef __TEST_ARRAY_VOID_H
#define __TEST_ARRAY_VOID_H

#define PRINT_STRING(string) printf("%s\n", string)

MapperVoid square_of_num_void;
MapperVoid convert_to_lowercase;
void test_map_void(void);

PredicateVoid is_even_void;
PredicateVoid is_vowel_void;
void test_filter_void(void);

ReducerVoid sum_void;
void test_reduce_void(void);

ArrayVoid_ptr create_int_ArrayVoid(int *values, int length);

#endif
