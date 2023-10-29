#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define LIST_DEBUG

typedef struct Node{
    struct Node* next;
    struct Node* prev;
    void* data;
}Node;

typedef struct List{
    Node *init;
    Node *last;
    uint32_t n_elems;
}List;

// Initialization of the list
int8_t init_list(List* l);

// Add a node into the selected position
int8_t add_node(List* l, void *v, uint32_t pos);

// Delete a node form the list
int8_t delete_node(List* l, void **v, uint32_t pos);

// Get the total of nodes of the list 
int8_t get_total_nodes(List* l);

// Get value in the position indicated 
int8_t get_value(List* l, void** v, uint32_t pos);

Node* get_node(List* l, int pos);

int swap_nodes_by_pos(uint32_t pos1, uint32_t pos2, List* l);
int move_node_by_pos(uint32_t node_pos, uint32_t final_pos, List* l);

#if defined LIST_DEBUG
void print_node_list_value(List* l);
#endif

#endif //LIST
