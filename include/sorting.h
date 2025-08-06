#ifndef SORTING
#define SORTING

#include "list.h"
#include <stdint.h>

typedef int8_t (*compare_func)(void* a, void* b);
typedef node_t* (*pivot_node_func)(list_t *l, uint32_t pos);

int8_t mergeSort(list_t *l, int init, int end);

// int8_t radixSort(list_t *l);

int8_t quickSort(list_t *l, int32_t init, int32_t end);

int8_t sorting_set_compare_function(uint8_t comp_func_id, compare_func func);

int8_t sorting_set_pivot_function(uint8_t pivot_func_id, pivot_node_func func);

#endif //SORTING
