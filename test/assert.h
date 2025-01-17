#ifndef __ASSERT_H
#define __ASSERT_H

#include "../array_void.h"

#define FOR_EACH(startAt, endAt) for (int i = startAt; i < endAt; i++)

Bool assert_integer(int actual, int expected);
Bool assert_Array(Array *actual, Array *expected);

Bool assert_integer_void(Object actual, Object expected);
Bool assert_character_void(Object actual, Object expected);
Bool assert_ArrayVoid(ArrayVoid_ptr actual, ArrayVoid_ptr expected, Bool asserter(Object, Object));

#endif
