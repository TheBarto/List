#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//#define LIST_DEBUG
#define LIST_DYNAMIC_NODES

#define GET_NODE_LIST(node, pos) \
do{ \
	for(uint32_t i = 0; ((i < pos) && (node)); i++, node = node->next); \
}while(0)

typedef struct node_t {
	struct node_t *next;
	struct node_t *prev;
	void *data;
} node_t;

typedef struct list_t {
	node_t *init;
	node_t *last;
	uint32_t n_elems;
} list_t;

/**
 * @brief Basic list initializaction
 * @param l list
 * @return 0 ok, -1 error
 */
int8_t list_init_list(list_t *l);

/**
 * @brief Add a node at the end of the list
 * @param l list
 * @param v void ptr to the object to save
 * @param n node use to save the
 *          information at the list
 * @return 0 ok, -1 error
 */
int8_t list_add_node(list_t *l, void *v, node_t * n);

/**
 * @brief Add a node into the selected position of the list
 * @param l list
 * @param v void ptr to the object to save
 * @param n node use to save the
 *          information at the list
 * @return 0 ok, -1 error
 */
int8_t list_add_pos_node(list_t *l, void *v, uint32_t pos, node_t * n);

/**
 * @brief Delete a node from the lastest list's position
 * @param l list
 * @param v void ptr to the object to save
 * @return 0 ok, -1 error
 */
uint8_t list_delete_node(list_t *l, void **v);

/**
 * @brief Delete a node from the selected list's position
 * @param l list
 * @param v void ptr to the object to save
 * @return 0 ok, -1 error
 */
uint8_t list_delete_pos_node(list_t *l, void **v, uint32_t pos);

/**
 * @brief Gets the total list elements
 * @param l list
 * @return number of elements if ok, -1 error
 */
int8_t list_get_total_nodes(list_t *l);

/**
 * @brief Gets the value saved in a specific node
 * @param l list
 * @param v pointer to pointer to retrieve the node information.
 * @param pos node's position
 *
 * @return 0 ok, -1 error
 */
int8_t list_get_value(list_t *l, void** v, uint32_t pos);

/**
 * @brief Gets the a specific node
 * @param l list
 * @param pos node's position
 *
 * @return 0 ok, -1 error
 */
node_t * list_get_node(list_t *l, int pos);

/**
 * @brief Swap two nodes by their positions
 * @param pos1 node1's position
 * @param pos2 node2's position
 * @param l list
 *
 * @return 0 ok, -1 error
 */
int8_t list_swap_nodes_by_pos(list_t *l, uint32_t pos1, uint32_t pos2);

/**
 * @brief Move one node at put it at the indicated position
 * @param node_pos node's original position
 * @param final_pos node's final position
 * @param l list
 *
 * @return 0 ok, -1 error
 */
int8_t list_move_node_by_pos(list_t *l, uint32_t node_pos, uint32_t final_pos);

#ifdef LIST_DYNAMIC_NODES
/**
 * @brief Add a dynamic node at the end of the list
 * @param l list
 * @param v void ptr to the object to save
 * @param n node use to save the
 *          information at the list
 * @return 0 ok, -1 error
 */
int8_t list_add_d_node(list_t *l, void* v);

/**
 * @brief Add a dynamic node into the selected position of the list
 * @param l list
 * @param v void ptr to the object to save
 * @param n node use to save the
 *          information at the list
 * @return 0 ok, -1 error
 */
int8_t list_add_d_pos_node(list_t *l, void* v, uint32_t pos);

/**
 * @brief Delete dynamic a node from the lastest list's position
 * @param l list
 * @param v void ptr to the object to save
 * @return 0 ok, -1 error
 */
uint8_t list_delete_d_node(list_t *l, void **v);

/**
 * @brief Delete a dynamic node from the selected list's position
 * @param l list
 * @param v void ptr to the object to save
 * @return 0 ok, -1 error
 */
uint8_t list_delete_d_pos_node(list_t *l, void **v, uint32_t pos);

#endif /* LIST_DYNAMIC_NODES */
#ifdef LIST_DEBUG
/**
 * @brief Prints all list's elements as integers
 * @param l list
 */
void print_node_list_value(list_t * l);
#endif /* LIST_DEBUG */

#endif //LIST
