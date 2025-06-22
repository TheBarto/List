#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

typedef List Queue;

#define init_queue(q) init_list(q)
#define queue_value(q, v, n) add_node(q, v, n)
#define unqueue_value(q, v) delete_pos_node(q, v, 0)
#define queue_d_value(q, v) add_d_node(q, v)
#define unqueue_d_value(q, v) delete_d_pos_node(q, v, 0)
#define get_queue_size(q) get_total_nodes(q)

#endif
