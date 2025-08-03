#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "list.h"
#include "stack.h"
#include "queue.h"
#include "sorting.h"

#define LIST_DYNAMIC_NODES

void check_list_functionality()
{
	list_t l;

	assert(!list_init_list(&l));

	int a[5] = {456, -43, 0, 1234, 98176};
	assert(!list_add_d_pos_node(&l, (void *)&a[0], 0));
	assert(!list_add_d_pos_node(&l, (void *)&a[1], 2));
	assert(!list_add_d_pos_node(&l, (void *)&a[4], 0));
	assert(!list_add_d_pos_node(&l, (void *)&a[2], 0));
	assert(!list_add_d_pos_node(&l, (void *)&a[1], 0));

	assert(!list_add_d_pos_node(&l, (void *)&a[3], 100));
	assert(!list_add_d_pos_node(&l, (void *)&a[1], 1));
	assert(!list_add_d_pos_node(&l, (void *)&a[2], 2));
	
	assert(list_get_total_nodes(&l) < 127);
#if defined LIST_DEBUG
	list_print_node_list_value(&l);
#endif

	int *ptr = NULL;
	printf("Start to check nodes\n");
	assert(!list_get_value(&l, (void **)&ptr, 0));
	printf("Pos: %d - Value obtained: %d\n", 0, *ptr);
	
	assert(!list_get_value(&l, (void **)&ptr, 1));
	printf("Pos: %d - Value obtained: %d\n", 1, *ptr);
	
	assert(!list_get_value(&l, (void **)&ptr, 2));
	printf("Pos: %d - Value obtained: %d\n", 2, *ptr);
	
	assert(!list_get_value(&l, (void **)&ptr, 3));
	printf("Pos: %d - Value obtained: %d\n", 3, *ptr);
	
	assert(!list_get_value(&l, (void **)&ptr, 4));
	printf("Pos: %d - Value obtained: %d\n", 4, *ptr);
	
	assert(!list_get_value(&l, (void **)&ptr, 5));
	printf("Pos: %d - Value obtained: %d\n", 5, *ptr);
	
	assert(!list_get_value(&l, (void **)&ptr, 6));
	printf("Pos: %d - Value obtained: %d\n", 6, *ptr);
	
	assert(!list_get_value(&l, (void **)&ptr, 7));
	printf("Pos: %d - Value obtained: %d\n", 7, *ptr);

	printf("Start to delete nodes\n");
	assert(!list_delete_d_pos_node(&l, (void **)&ptr, 7));
	printf("Pos: %d - Value obtained: %d\n", 7, *ptr);

	assert(!list_delete_d_pos_node(&l, (void **)&ptr, 6));
	printf("Pos: %d - Value obtained: %d\n", 6, *ptr);
	
	assert(!list_delete_d_pos_node(&l, (void **)&ptr, 5));
	printf("Pos: %d - Value obtained: %d\n", 5, *ptr);
	
	assert(!list_delete_d_pos_node(&l, (void **)&ptr, 4));
	printf("Pos: %d - Value obtained: %d\n", 4, *ptr);

	assert(!list_delete_d_pos_node(&l, (void **)&ptr, 3));
	printf("Pos: %d - Value obtained: %d\n", 3, *ptr);

	assert(!list_delete_d_pos_node(&l, (void **)&ptr, 2));
	printf("Pos: %d - Value obtained: %d\n", 2, *ptr);
	
	assert(!list_delete_d_pos_node(&l, (void **)&ptr, 1));
	printf("Pos: %d - Value obtained: %d\n", 1, *ptr);
	
	assert(!list_delete_d_pos_node(&l, (void **)&ptr, 0));
	printf("Pos: %d - Value obtained: %d\n", 0, *ptr);

	assert(!list_add_d_pos_node(&l, (void *)&a[1], 2));
	assert(!list_add_d_pos_node(&l, (void *)&a[4], 0));
#if defined LIST_DEBUG
	list_print_node_list_value(&l);
#endif
	return;
}

void check_stack_functionality()
{
	stack_t s;
	int a[5] = {456, -43, 0, 1234, 98176};
	
	assert(!stack_init_stack(&s));

	assert(!stack_stack_d_value(&s, (void *)&a[0])); 
	assert(!stack_stack_d_value(&s, (void *)&a[1])); 
	assert(!stack_stack_d_value(&s, (void *)&a[2])); 
	assert(!stack_stack_d_value(&s, (void *)&a[3])); 
	assert(!stack_stack_d_value(&s, (void *)&a[4])); 

	int *ptr = NULL;
	assert(!stack_unstack_d_value(&s, (void **)&ptr));
	printf("Value unstacked is %d\n", *ptr);

	assert(!stack_unstack_d_value(&s, (void **)&ptr));
	printf("Value unstacked is %d\n", *ptr);
	
	assert(!stack_unstack_d_value(&s, (void **)&ptr));
	printf("Value unstacked is %d\n", *ptr);
	
	assert(!stack_unstack_d_value(&s, (void **)&ptr));
	printf("Value unstacked is %d\n", *ptr);

	assert(!stack_unstack_d_value(&s, (void **)&ptr));
	printf("Value unstacked is %d\n", *ptr);
	
	assert(!stack_unstack_d_value(&s, (void **)&ptr));
	printf("Value must be the same, the stack is empty: %d\n", *ptr);
	
	return;
}

void check_queue_functionality()
{
	queue_t q;

	assert(!queue_init_queue(&q));
	int a[5] = {456, -43, 0, 1234, 98176};
  
	queue_get_queue_size(&q);
	assert(!queue_queue_d_value(&q, (void *)&a[3]));
	assert(!queue_queue_d_value(&q, (void *)&a[4]));
	assert(!queue_queue_d_value(&q, (void *)&a[0]));
	assert(!queue_queue_d_value(&q, (void *)&a[1]));
	assert(!queue_queue_d_value(&q, (void *)&a[2]));

	int* ptr = NULL;
	assert(!queue_unqueue_value(&q, (void **)&ptr));
	printf("Value unqueue is %d\n", *ptr);
	
	assert(!queue_unqueue_value(&q, (void **)&ptr));
	printf("Value unqueue is %d\n", *ptr);
	
	assert(!queue_unqueue_value(&q, (void **)&ptr));
	printf("Value unqueue is %d\n", *ptr);
	
	assert(!queue_unqueue_value(&q, (void **)&ptr));
	printf("Value unqueue is %d\n", *ptr);
	
	assert(!queue_unqueue_value(&q, (void **)&ptr));
	printf("Value unqueue is %d\n", *ptr);
	
	assert(!queue_unqueue_value(&q, (void **)&ptr));
	printf("Couldn't unqueue more values, queue are empty: %d\n", *ptr);

	return;
}

int compare_two_elements(void* a, void* b)
{
	int a1 = *(int *)a;
	int b1 = *(int *)b;

#if defined(LIST_DEBUG)
	printf("Valor a1: %d --- b1: %d\n", a1, b1);
#endif

	if(a1 == b1)
		return 0;
	else if(a1 < b1)
		return -1;
	else
		return 1;
}

void check_sorting_functionality()
{
	list_t l;

	assert(!list_init_list(&l));

	int a[8] = {38, 27, 43, 3, 9, 82, 10};
	
	assert(!list_add_d_pos_node(&l, (void *)&a[0], 0));
	assert(!list_add_d_pos_node(&l, (void *)&a[1], 1));
	assert(!list_add_d_pos_node(&l, (void *)&a[2], 2));
	assert(!list_add_d_pos_node(&l, (void *)&a[3], 3));
	assert(!list_add_d_pos_node(&l, (void *)&a[4], 4));
	assert(!list_add_d_pos_node(&l, (void *)&a[5], 5));
	assert(!list_add_d_pos_node(&l, (void *)&a[6], 6));

#if defined LIST_DEBUG
	list_print_node_list_value(&l);
#endif

#if 0
#if defined LIST_DEBUG
	printf("Before the swap\n");
	list_print_node_list_value(&l);
#endif
	
	list_swap_nodes_by_pos(1, 6, &l);

#if defined LIST_DEBUG
	printf("After the swap\n");
	list_print_node_list_value(&l);
#endif

	list_move_node_by_pos(5, 0, &l);

#if defined LIST_DEBUG
	printf("After the move\n");
	list_print_node_list_value(&l);
#endif

	list_move_node_by_pos(1, , &l);

#if defined LIST_DEBUG
	printf("After the move\n");
	list_print_node_list_value(&l);
#endif
#endif

#if 1
	mergeSort(&l, 0, 6, &compare_two_elements);
#if defined LIST_DEBUG
	printf("After the sort\n");
	list_print_node_list_value(&l);
#endif
#endif
	return;
}

int main(int argc, char* argv[])
{
	check_list_functionality();
	check_stack_functionality();
	check_queue_functionality();
	//check_sorting_functionality();

	printf("End process\n");
	return EXIT_SUCCESS;
}
