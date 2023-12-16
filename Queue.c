#include "Queue.h"

int init_queue(Queue* q)
{
   if(!q)
       return -1;

   return init_list(q);
}

int queue_value(Queue* q, void* v, Node* n)
{
    return add_node(q, v, q->n_elems, n);
}

int queue_d_value(Queue* q, void* v)
{
    return add_d_node(q, v, q->n_elems);
}

int unqueue_value(Queue* q, void** v)
{
    return delete_node(q, v, 0);
}

int unqueue_d_value(Queue* q, void** v)
{
    return delete_d_node(q, v, 0);
}

int get_queue_size(Queue* q)
{
    return q->n_elems;
}
