#ifndef LIST
#define LIST

#include <stdint.h>
#include <stdlib.h>

typedef struct List{
    Node *ini;
    Node *fin;
    uint32_t n_elems;
}List;

typedef struct Node{
    struct Node* next;
    struct Node* prev;
    void* data;
}Node;

// Initialization of the list
int8_t init_list(List* l);

// Add a node into the selected position
int8_t add_value(List* l, void *v, uint32_t pos);

// Delete a node form the list
int8_t delete_node(List* l, void *v, uint32_t pos);

// Get the total of nodes of the list 
int8_t get_total_nodes(List* l);

// Get value in the position indicated 
int8_t get_value(List* l, void* v, uint32_t pos);

#endif LIST
