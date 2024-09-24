#ifndef STACK_H
#define STACK_H

#include "List.h"

typedef List Stack;

#define init_stack(s) init_list(s)
#define stack_value(s, v, n) add_node(s, v, n)
#define unstack_value(s, v) delete_node(s, v)
#define stack_d_value(s, v) add_d_node(s, v)
#define unstack_d_value(s, v) delete_d_node(s, v)
#define get_stack_size(s) get_total_nodes(s)

#endif
