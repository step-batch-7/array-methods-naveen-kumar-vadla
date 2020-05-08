#ifndef __ASSERT_H
#define __ASSERT_H

#define FOR_EACH(startAt, endAt) for (int i = startAt; i < endAt; i++)

// ✔ = \u2714  HEAVY CHECK MARK
// ✘ = \u2718  HEAVY BALLOT X

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define PASS GREEN "\u2714 " RESET
#define FAIL RED "\u2718 " RESET

Bool assert_integer(int actual, int expected);
Bool assert_Array(Array *actual, Array *expected);

#endif
