#include "sorting.h"
#include <stdio.h>

static int8_t compare_int32_elements(void* a, void* b)
{
	int32_t a1 = *(int32_t *)a;
	int32_t b1 = *(int32_t *)b;

#ifdef LIST_DEBUG
	printf("Valor a1: %d --- b1: %d\n", a1, b1);
#endif

	if(a1 == b1)
		return 0;
	else if(a1 < b1)
		return -1;
	else
		return 1;
}

static inline node_t* sorting_first_node_pivot(list_t *l, uint32_t init_pos)
{
	node_t *node = l->init;
	GET_NODE_LIST(node, init_pos);
	return node;
}

static inline node_t* sorting_last_node_pivot(list_t *l, uint32_t end_pos)
{
	node_t *node = l->init;
	GET_NODE_LIST(node, end_pos);
	return node;
}

compare_func comp_func = compare_int32_elements;
pivot_node_func pivot_func = sorting_last_node_pivot;

static int8_t merge(list_t *l, int init, int m, int end)
{
	printf("Start Merge - init: %d, middle: %d, end: %d\n", init, m, end);
	list_print_list_nodes_values(l);

	// position to know if we're into the limits
	uint32_t pos_i = 0, pos_j = 0;
	// position limit to compare the values 
	uint32_t aux_i = (m-init+1), aux_j = (end-m);
	// index to swap the positions
	uint32_t cont_i = init, cont_j = m+1;
	node_t *n1 = list_get_node(l, init);
	node_t *n2 = list_get_node(l, (m+1));

	while((pos_i < aux_i) && (pos_j < aux_j) && (n1) && (n2)) {
		if(comp_func(n1->data, n2->data) > 0) {
			n2=n2->next;
			list_move_node_by_pos(l, cont_j, cont_i);
			cont_j++;
			pos_j++;
		} else {
			n1=n1->next;
			pos_i++;
		}
		/* Always going to use the leftmost position. If we swap, we use it
		 * and if do not swap, the element must remain at that position, so
		 * do not touch that position
		 */
		cont_i++;
	}

#if defined LIST_DEBUG
	printf("After merge iteration\n");
	list_print_list_nodes_values(l);
#endif
	return 0;
}

int8_t mergeSort(list_t *l, int init, int end)
{
	if (!l/* || !func*/ || (init >= end))
		return -1;

	uint32_t aux_m = (((end-init)/2)+init);
	mergeSort(l, init, aux_m);
	mergeSort(l, aux_m+1, end);

	return merge(l, init, aux_m, end);
}

static uint32_t partition(list_t *l, int32_t init, int32_t end)
{
	// For the example, choose the last position
	int i = init-1;
	node_t *n = list_get_node(l, init);
	node_t *n2 = n;
	node_t *node_pivot = pivot_func(l, end);

	// It's done end-1 to avoid compare the lastest position with himself
	for(uint32_t j = init; j < end; j++, n=n->next) {
		if(comp_func(n->data, node_pivot->data) < 0) {
			if(n != n2)
				list_swap_nodes_data(n2, n);
			n2 = n2->next;
			i++;
		}
	}

	// Swap the pivot value and the following value
	list_swap_nodes_data(n2, node_pivot);
	i++;
	return i;
}

int8_t quickSort(list_t *l, int32_t init, int32_t end)
{
	if(!l || init >= end)
		return -1;

	uint32_t middle = partition(l, init, end);

	/* Do not touch the middle position. The
	 * element at that position is at the
	 * perfect position
	 */
	quickSort(l, init, middle-1);
	quickSort(l, middle+1, end);

	return 0;
}

int8_t sorting_set_compare_function(uint8_t comp_func_id, compare_func func)
{
	if(func) {
		comp_func = func;
		return 0;
	}

	switch(comp_func_id) {
		case 0:
		comp_func = &compare_int32_elements;
		break;
		default: return -1;
	}

	return 0;
}

int8_t sorting_set_pivot_function(uint8_t pivot_func_id, pivot_node_func func)
{
	if(func) {
		pivot_func = func;
		return 0;
	}
	switch(pivot_func_id) {
		case 0:
		pivot_func = &sorting_first_node_pivot;
		break;
		case 1:
		pivot_func = &sorting_last_node_pivot;
		default: return -1;
	}

	return 0;
}
