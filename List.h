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

int8_t add_d_node(List* l, void* v, uint32_t pos);
// Add a node into the selected position. If n it's != NULL, use that one
// and do not reserve dinamically another
int8_t add_node(List* l, void *v, uint32_t pos, Node* n);
int8_t internal_add_node(List* l, void *v, uint32_t pos, Node* n);

// Delete a node form the list
// Delete an non dinamic node
int8_t internal_delete_node(List* l, void **v, uint32_t pos, Node** fnode);
uint8_t delete_node(List* l, void **v, uint32_t pos);
uint8_t delete_d_node(List* l, void **v, uint32_t pos);

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
