#include "List.h"

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
int8_t add_value(List* l, void *v, uint32_t pos)
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

    if(pos > l->n_elems)
    {
        n->prev = l->last;
        l->last->next = n;
        l->last = n;
    }
    else
    {
        Node* aux = l->first;
        for(uint32_t i = 0; ((i < pos) && (aux)); aux = aux->next);
        aux->value = val;

        n->next = aux;
        n->prev = aux->prev;
        if(aux->prev)
        {
            aux->prev->next = n;
            aux->prev = n;
        }
        else
        {
            l->first = n;
        }
    }

    return 0;
}

// Delete a node form the list
int8_t delete_node(List* l, void *v, uint32_t pos)
{
    if(!l || !v)
    {
        return -1;
    }

    if(pos > l->n_elems)
    {
        return -1;
    }
    Node *aux = l->first;
    for(uint32_t i = 0; ((i < pos) && (!aux)); aux = aux->next);

    if(!aux->next)
        l->last = aux->prev;
    else
        aux->next->prev = aux->prev;

    if(!aux->prev)
        l->first = aux->next;
    else
        aux->prev->next = aux->next;

    n->next = n->prev = NULL;
    v = n->data;

    free(n);

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
int8_t get_value(List* l, void* v, uint32_t pos)
{
    if(!l || !v)
    {
        return -1;
    }

    if(pos >= l->n_elems)
    {
        return -1;
    }

    Node* n = l->first;

    for(uint32_t i = 0; i < pos; i++, n=n->next);

    v = n->data;

    return 0;
}

