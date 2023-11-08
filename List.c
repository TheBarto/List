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

    if(!l->n_elems)
        return 0;
    else if(pos > l->n_elems) 
        return -1;
    
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

    if(!l->n_elems)
    {
        l->init = l->last = NULL;
    }
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

Node* get_node(List* l, int pos)
{
    Node* n = l->init;
    for(int i = 0; ((i < pos) && n); i++, n=n->next);

    return n;
}

int swap_nodes_by_pos(uint32_t pos1, uint32_t pos2, List* l)
{
    Node* n1 = NULL;
    Node* n2 = NULL;
    Node* n_aux = l->init;
    
    for(uint32_t i = 0; ((i < l->n_elems) && ((!n1) || (!n2))); i++, n_aux=n_aux->next)
    {
       if(i == pos1)
           n1 = n_aux;
       if(i == pos2)
           n2 = n_aux;
    }

    //Better two pointer instead a Node to save space?
    Node aux;
    aux.prev = n2->prev;
    aux.next = n2->next;

   (n1->prev) ? (n1->prev->next = n2) : (l->init = n2);
   (n1->next) ? (n1->next->prev = n2) : (l->last = n2); 
    n2->prev = n1->prev;
    n2->next = n1->next;

   (aux.prev) ? (aux.prev->next = n1) : (l->init = n1);
   (aux.next) ? (aux.next->prev = n1) : (l->last = n1); 
    n1->prev = aux.prev;
    n1->next = aux.next;

   return 0;
}

int move_node_by_pos(uint32_t node_pos, uint32_t final_pos, List* l)
{
    Node* n_aux = l->init;
    Node* n_move = NULL;
    Node* n_fin_pos = NULL;
    for(uint32_t i = 0; 
            ((i < l->n_elems) && ((!n_move) || (!n_fin_pos))); 
            i++, n_aux=n_aux->next)
    {
        if(i == node_pos)
            n_move = n_aux;
        if(i == final_pos)
            n_fin_pos = n_aux;
    }
   
    // Extract the node from this actual position
    (n_move->prev) ? (n_move->prev->next = n_move->next) : (l->init = n_move->next);
    (n_move->next) ? (n_move->next->prev = n_move->prev) : (l->last = n_move->prev);

    // Set the node in the new position
    n_move->next = n_fin_pos;
    n_move->prev = n_fin_pos->prev;
    (n_move->next) ? (n_move->next->prev = n_move) : (l->last=n_move);
    (n_move->prev) ? (n_move->prev->next = n_move) : (l->init=n_move);
    //n_fin_pos->next = n_move;
    //n_move->prev = n_fin_pos;

#if defined LIST_DEBUG
#include <stdio.h>
    printf("After move node\n");
    print_node_list_value(l);
#endif

    return 0;
}
