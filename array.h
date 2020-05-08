#ifndef __ARRAY_H
#define __ARRAY_H
typedef enum
{
  False,
  True
} Bool;

typedef int(Mapper)(int);
typedef Bool(Predicate)(int);
typedef int(Reducer)(int, int);

typedef struct
{
  int *array;
  int length;
} Array;

Array *map(Array *src, Mapper *mapper);
Array *filter(Array *src, Predicate *predicate);
int reduce(Array *src, int init, Reducer *reducer);

#define FOR_EACH(startAt, endAt) for (int i = startAt; i < endAt; i++)
#define PRINT_STRING(string) printf("%s\n", string)

Array *create_Array_from(int *values, int length);
void display_Array(Array *array);

#endif
