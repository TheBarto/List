#include "Queue.h"

int queue_value(Queue* q, void* v)
{
    return add_node(q, v, q->n_elems);
}

int unqueue_value(Queue* q, void** v)
{
    return delete_node(q, v, q->n_elems-1);
}

int get_queue_size(Queue* q)
{
    return q->n_elems;
}
