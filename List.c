#include "List.h"

#include <stdio.h>

// Initialization of the list
int8_t init_list(List* l)
{
    if(!l)
    {
        return -1;
    }

    memset(l, 0, sizeof(List));

    return 0;
}

// Add a node into the selected position
int8_t add_node(List* l, void *v, uint32_t pos)
{
    if(!l || !v)
    {
        return -1;
    }
    
    Node *n = (Node *)malloc(sizeof(Node));
    if(!n)
    {
        return -1;
    }
    memset(n, 0, sizeof(Node));

    n->data = v; 
    if(!l->init)
    {
        l->init = n;
        l->last = n;
    }
    else if(pos >= l->n_elems)
    {
        n->prev = l->last;
        if(l->last)
            l->last->next = n;
        l->last = n;
    }
    else
    {
        Node* aux = l->init;
        for(uint32_t i = 0; ((i < pos) && (aux)); i++, aux = aux->next);

        n->next = aux;
        if(aux->prev) aux->prev->next = n;
        else l->init = n;
        n->prev = aux->prev;
        aux->prev = n;
    }
    l->n_elems++;

    return 0;
}

// Delete a node form the list
int8_t delete_node(List* l, void **v, uint32_t pos)
{
    if(!l || !v)
    {
        return -1;
    }

    if(pos > l->n_elems)
    {
        return -1;
    }
    Node *aux = l->init;
    for(uint32_t i = 0; ((i < pos) && (aux)); i++, aux = aux->next);

    if(!aux->next)
        l->last = aux->prev;
    else
        aux->next->prev = aux->prev;

    if(!aux->prev)
        l->init = aux->next;
    else
        aux->prev->next = aux->next;

    aux->next = aux->prev = NULL;
    *v = aux->data;

    free(aux);
    l->n_elems--;

    return 0;
}

// Get the total of nodes of the list 
int8_t get_total_nodes(List* l)
{
    if(!l)
    {
        return -1;
    }

    return l->n_elems;
}

// Get value in the position indicated 
int8_t get_value(List* l, void** v, uint32_t pos)
{
    if(!l || !v)
    {
        return -1;
    }

    if(pos >= l->n_elems)
    {
        return -1;
    }

    Node* n = l->init;

    for(uint32_t i = 0; ((i < pos) && (n)); i++, n=n->next);
    *v = n->data;

    return 0;
}

#if defined LIST_DEBUG 
void print_node_list_value(List* l)
{
    Node* n = l->init;
    uint32_t i = 0;

    while(n)
    {
        printf("Node: %d - Val: %d \n", i, *(int32_t *)n->data);
        n = n->next;
        i++;
    }
}
#endif
