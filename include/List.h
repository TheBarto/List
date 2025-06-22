#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define LIST_DEBUG

#define GET_NODE_LIST(node, pos) do{ for(uint32_t i = 0; ((i < pos) && (node)); i++, node = node->next);}while(0)

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

//Add a node at the end of the list
int8_t add_d_node(List* l, void* v);
//Add a dinamic node at the end of the list
int8_t add_node(List* l, void *v, Node* n);

//Add a dinamic node to the list
int8_t add_d_pos_node(List* l, void* v, uint32_t pos);
// Add a node into the selected position. If n it's != NULL, use that one
// and do not reserve dinamically another
int8_t add_pos_node(List* l, void *v, uint32_t pos, Node* n);

// Delete a node form the list with the position
// Delete an non dinamic node with the position
uint8_t delete_pos_node(List* l, void **v, uint32_t pos);
uint8_t delete_d_pos_node(List* l, void **v, uint32_t pos);

// Delete a node form the list in last position
// Delete an non dinamic node in last position
uint8_t delete_node(List* l, void **v);
uint8_t delete_d_node(List* l, void **v);

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
