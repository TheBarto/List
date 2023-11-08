#ifndef QUEUE_H
#define QUEUE_H

#include "Stack.h"

typedef List Queue;

int init_queue(Queue* q);

int queue_value(Queue* q, void* v);

int unqueue_value(Queue* q, void** v);

int get_queue_size(Queue* q);

#endif
