#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef list_t queue_t;

#define queue_init_queue(q) list_init_list(q)
#define queue_queue_value(q, v, n) list_add_node(q, v, n)
#define queue_unqueue_value(q, v) list_delete_pos_node(q, v, 0)
#define queue_queue_d_value(q, v) list_add_d_node(q, v)
#define queue_unqueue_d_value(q, v) list_delete_d_pos_node(q, v, 0)
#define queue_get_queue_size(q) list_get_total_nodes(q)

#endif
