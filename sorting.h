#ifndef SORTING
#define SORTING

#include "List.h"
#include <stdint.h>

typedef int (*compare_func)(void* a, void* b);

int8_t mergeSort(List* l, int init, int end, compare_func func);
int8_t merge(List* l, int init, int m, int end, compare_func func);

int8_t radixSort(List* l);

#endif //SORTING
