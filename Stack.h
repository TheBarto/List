#ifndef STACK_H
#define STACK_H

#include "List.h"

typedef List Stack;

int init_stack(Stack* s);

int stack_value(Stack* s, void* v, Node* n);

int unstack_value(Stack* s, void** v);

int stack_d_value(Stack* s, void* v);

int unstack_d_value(Stack* s, void** v);

int get_stack_size(Stack* s);

#endif
