#ifndef SORTING
#define SORTING

#include "list.h"
#include <stdint.h>

typedef int (*compare_func)(void* a, void* b);

int8_t mergeSort(list_t *l, int init, int end, compare_func func);
int8_t merge(list_t *l, int init, int m, int end, compare_func func);

int8_t radixSort(list_t *l);

#endif //SORTING
