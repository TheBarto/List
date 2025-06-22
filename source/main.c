#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "sorting.h"

void check_list_functionality()
{
	List l;

	assert(init_list(&l) == 0);

	int a[5] = {456, -43, 0, 1234, 98176};
	assert(add_d_pos_node(&l, (void *)&a[0], 0) == 0);
	assert(add_d_pos_node(&l, (void *)&a[1], 2) == 0);
	assert(add_d_pos_node(&l, (void *)&a[4], 0) == 0);
	assert(add_d_pos_node(&l, (void *)&a[2], 0) == 0);
	assert(add_d_pos_node(&l, (void *)&a[1], 0) == 0);

	assert(add_d_pos_node(&l, (void *)&a[3], 100) == 0);
	assert(add_d_pos_node(&l, (void *)&a[1], 1) == 0);
	assert(add_d_pos_node(&l, (void *)&a[2], 2) == 0);
	
	assert(get_total_nodes(&l) < 1004);
#if defined LIST_DEBUG
	print_node_list_value(&l);
#endif

	int *ptr = NULL;
	assert(get_value(&l, (void **)&ptr, 0) == 0);
	printf("Pos: %d - Value obtained: %d\n", 0, *ptr);
	
	assert(get_value(&l, (void **)&ptr, 1) == 0);
	printf("Pos: %d - Value obtained: %d\n", 1, *ptr);
	
	assert(get_value(&l, (void **)&ptr, 2) == 0);
	printf("Pos: %d - Value obtained: %d\n", 2, *ptr);
	
	assert(get_value(&l, (void **)&ptr, 3) == 0);
	printf("Pos: %d - Value obtained: %d\n", 3, *ptr);
	
	assert(get_value(&l, (void **)&ptr, 4) == 0);
	printf("Pos: %d - Value obtained: %d\n", 4, *ptr);
	
	assert(get_value(&l, (void **)&ptr, 5) == 0);
	printf("Pos: %d - Value obtained: %d\n", 5, *ptr);
	
	assert(get_value(&l, (void **)&ptr, 6) == 0);
	printf("Pos: %d - Value obtained: %d\n", 6, *ptr);
	
	assert(get_value(&l, (void **)&ptr, 7) == 0);
	printf("Pos: %d - Value obtained: %d\n", 7, *ptr);
	
	assert(delete_d_pos_node(&l, (void **)&ptr, 7) == 0);
	printf("Pos: %d - Value obtained: %d\n", 7, *ptr);

	assert(delete_d_pos_node(&l, (void **)&ptr, 6) == 0);
	printf("Pos: %d - Value obtained: %d\n", 6, *ptr);
	
	assert(delete_d_pos_node(&l, (void **)&ptr, 5) == 0);
	printf("Pos: %d - Value obtained: %d\n", 5, *ptr);
	
	assert(delete_d_pos_node(&l, (void **)&ptr, 4) == 0);
	printf("Pos: %d - Value obtained: %d\n", 4, *ptr);

	assert(delete_d_pos_node(&l, (void **)&ptr, 3) == 0);
	printf("Pos: %d - Value obtained: %d\n", 3, *ptr);

	assert(delete_d_pos_node(&l, (void **)&ptr, 2) == 0);
	printf("Pos: %d - Value obtained: %d\n", 2, *ptr);
	
	assert(delete_d_pos_node(&l, (void **)&ptr, 1) == 0);
	printf("Pos: %d - Value obtained: %d\n", 1, *ptr);
	
	assert(delete_d_pos_node(&l, (void **)&ptr, 0) == 0);
	printf("Pos: %d - Value obtained: %d\n", 0, *ptr);

	assert(add_d_pos_node(&l, (void *)&a[1], 2) == 0);
	assert(add_d_pos_node(&l, (void *)&a[4], 0) == 0);
#if defined LIST_DEBUG
	print_node_list_value(&l);
#endif
	return;
}

void check_stack_functionality()
{
	Stack s;
	int a[5] = {456, -43, 0, 1234, 98176};
	
	assert(init_stack(&s) == 0);

	assert(stack_d_value(&s, (void *)&a[0]) == 0); 
	assert(stack_d_value(&s, (void *)&a[1]) == 0); 
	assert(stack_d_value(&s, (void *)&a[2]) == 0); 
	assert(stack_d_value(&s, (void *)&a[3]) == 0); 
	assert(stack_d_value(&s, (void *)&a[4]) == 0); 

	int *ptr = NULL;
	assert(unstack_d_value(&s, (void **)&ptr) == 0);
	printf("Value unstacked is %d\n", *ptr);

	assert(unstack_d_value(&s, (void **)&ptr) == 0);
	printf("Value unstacked is %d\n", *ptr);
	
	assert(unstack_d_value(&s, (void **)&ptr) == 0);
	printf("Value unstacked is %d\n", *ptr);
	
	assert(unstack_d_value(&s, (void **)&ptr) == 0);
	printf("Value unstacked is %d\n", *ptr);

	assert(unstack_d_value(&s, (void **)&ptr) == 0);
	printf("Value unstacked is %d\n", *ptr);
	
	assert(unstack_d_value(&s, (void **)&ptr) == 0);
	printf("Value must be the same, the stack is empty: %d\n", *ptr);
	
	return;
}

void check_queue_functionality()
{
	Queue q;

	assert(init_queue(&q) == 0);
	int a[5] = {456, -43, 0, 1234, 98176};
  
	get_total_nodes(&q);
	assert(queue_d_value(&q, (void *)&a[3]) == 0);
	assert(queue_d_value(&q, (void *)&a[4]) == 0);
	assert(queue_d_value(&q, (void *)&a[0]) == 0);
	assert(queue_d_value(&q, (void *)&a[1]) == 0);
	assert(queue_d_value(&q, (void *)&a[2]) == 0);

	int* ptr = NULL;
	assert(unqueue_value(&q, (void **)&ptr) == 0);
	printf("Value unqueue is %d\n", *ptr);
	
	assert(unqueue_value(&q, (void **)&ptr) == 0);
	printf("Value unqueue is %d\n", *ptr);
	
	assert(unqueue_value(&q, (void **)&ptr) == 0);
	printf("Value unqueue is %d\n", *ptr);
	
	assert(unqueue_value(&q, (void **)&ptr) == 0);
	printf("Value unqueue is %d\n", *ptr);
	
	assert(unqueue_value(&q, (void **)&ptr) == 0);
	printf("Value unqueue is %d\n", *ptr);
	
	assert(unqueue_value(&q, (void **)&ptr) == 0);
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
	List l;

	assert(init_list(&l) == 0);

	int a[8] = {38, 27, 43, 3, 9, 82, 10};
	
	assert(add_d_pos_node(&l, (void *)&a[0], 0) == 0);
	assert(add_d_pos_node(&l, (void *)&a[1], 1) == 0);
	assert(add_d_pos_node(&l, (void *)&a[2], 2) == 0);
	assert(add_d_pos_node(&l, (void *)&a[3], 3) == 0);
	assert(add_d_pos_node(&l, (void *)&a[4], 4) == 0);
	assert(add_d_pos_node(&l, (void *)&a[5], 5) == 0);
	assert(add_d_pos_node(&l, (void *)&a[6], 6) == 0);

	print_node_list_value(&l);
#if 0
#if defined LIST_DEBUG
	printf("Before the swap\n");
	print_node_list_value(&l);
#endif
	
	swap_nodes_by_pos(1, 6, &l);

#if defined LIST_DEBUG
	printf("After the swap\n");
	print_node_list_value(&l);
#endif

	move_node_by_pos(5, 0, &l);

#if defined LIST_DEBUG
	printf("After the move\n");
	print_node_list_value(&l);
#endif

	move_node_by_pos(1, , &l);

#if defined LIST_DEBUG
	printf("After the move\n");
	print_node_list_value(&l);
#endif
#endif

#if 1
	mergeSort(&l, 0, 6, &compare_two_elements);
#if defined LIST_DEBUG
	printf("After the sort\n");
	print_node_list_value(&l);
#endif
#endif
	return;
}

int main(int argc, char* argv[])
{
	//check_list_functionality();
	//check_stack_functionality();
	//check_queue_functionality();
	check_sorting_functionality();

	printf("End process\n");
	return EXIT_SUCCESS;
}
