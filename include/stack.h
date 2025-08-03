#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef list_t stack_t;

#define stack_init_stack(s) list_init_list(s)
#define stack_stack_value(s, v, n) list_add_node(s, v, n)
#define stack_unstack_value(s, v) list_delete_node(s, v)
#define stack_stack_d_value(s, v) list_add_d_node(s, v)
#define stack_unstack_d_value(s, v) list_delete_d_node(s, v)
#define stack_get_stack_size(s) list_get_total_nodes(s)

#endif
