#ifndef __ASSERT_H
#define __ASSERT_H

#define FOR_EACH(startAt, endAt) for (int i = startAt; i < endAt; i++)

Bool assert_integer(int actual, int expected);
Bool assert_Array(Array *actual, Array *expected);

#endif
