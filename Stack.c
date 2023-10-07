#include "Stack.h"

int init_stack(Stack* s);
{
    if(!s)
        return -1;

    return init_list(s);
}

int stack_value(Stack* s, void* v)
{
    return add_node(s, v, s->n_elems);
}

int unstack_value(Stack* s, void** v)
{
    return delete_node(s, v, s->n_elems-1);
}

int get_stack_size(Stack* s)
{
    return s->n_elems;
}

