#include "list.h"
#include <stdio.h>

static int8_t list_internal_add_node(list_t *l,
                                     void *v,
                                     uint32_t pos,
                                     node_t *n)
{
	if(!l || !v || !n)
		return -1;

	// Set the node's elems to NULL and save the data
	memset(n, 0, sizeof(node_t));
	n->data = v;

	if (!l->init) {
		l->init = n;
		l->last = n;
	} else if(pos >= l->n_elems) {
		n->prev = l->last;
		n->prev->next = n;
		l->last = n;
	} else {
		node_t * aux = l->init;
		GET_NODE_LIST(aux, pos);

		n->next = aux;
		/* Check if exists a previous of the current node,
		 * otherwise we're at the first position */
		(aux->prev) ? (aux->prev->next = n) : (l->init = n);
		n->prev = aux->prev;
		aux->prev = n;
	}
	l->n_elems++;

	return 0;
}

static int8_t list_internal_delete_node(list_t *l,
                                        void **v,
                                        uint32_t pos,
                                        node_t **fnode)
{
	if(!l || !v || (pos > l->n_elems))
		return -1;
	else if(!l->n_elems)
		return 0;

	node_t *aux = l->init;
	GET_NODE_LIST(aux, pos);

	/* Reorganize the previous and next pointer
	 * of the list after removing a node
	 */
	(!aux->next) ? (l->last = aux->prev) : (aux->next->prev = aux->prev);
	(!aux->prev) ? (l->init = aux->next) : (aux->prev->next = aux->next);

	/* Save node's information and save
	 * the memory address if it is needed
	 */
	aux->next = aux->prev = NULL;
	*v = aux->data;

	if(fnode)
		*fnode = aux;
	l->n_elems--;

	if(!l->n_elems)
		l->init = l->last = NULL;

	return 0;
}

int8_t list_init_list(list_t * l)
{
	if(!l)
		return -1;

	memset(l, 0, sizeof(list_t));
	return 0;
}

int8_t list_add_node(list_t *l, void *v, node_t *n)
{
	return list_internal_add_node(l, v, l->n_elems, n);
}

int8_t list_add_pos_node(list_t *l, void *v, uint32_t pos, node_t *n)
{
	return list_internal_add_node(l, v, pos, n);
}

uint8_t list_delete_node(list_t *l, void **v)
{
	return list_internal_delete_node(l, v, (l->n_elems-1), NULL);
}

uint8_t list_delete_pos_node(list_t *l, void **v, uint32_t pos)
{
	return list_internal_delete_node(l, v, pos, NULL);
}

int8_t list_get_total_nodes(list_t *l)
{
	return (!l)?-1:l->n_elems;
}

int8_t list_get_value(list_t *l, void **v, uint32_t pos)
{
	if(!l || !v || (pos >= l->n_elems))
		return -1;

	node_t * n = l->init;

	GET_NODE_LIST(n, pos);
	*v = n->data;

	return 0;
}

node_t * list_get_node(list_t *l, int pos)
{
	node_t * n = l->init;
	GET_NODE_LIST(n, pos);

	return n;
}

int8_t list_swap_nodes_by_pos(list_t *l, uint32_t pos1, uint32_t pos2)
{
	node_t * n1 = NULL;
	node_t * n2 = NULL;
	node_t * n_aux = l->init;

	for(uint32_t i = 0;
	    ((i < l->n_elems) && ((!n1) || (!n2)));
	    i++, n_aux=n_aux->next)
	{
		if(i == pos1)
			n1 = n_aux;
		if(i == pos2)
			n2 = n_aux;
	}
	void *ptr = n1->data;
	n1->data = n2->data;
	n2->data = ptr;

	return 0;
}

int8_t list_move_node_by_pos(list_t *l, uint32_t node_pos, uint32_t final_pos)
{
	node_t * n_aux = l->init;
	node_t * n_move = NULL;
	node_t * n_fin_pos = NULL;
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

#ifdef LIST_DEBUG
	printf("After move node\n");
	print_node_list_value(l);
#endif

	return 0;
}

#ifdef LIST_DYNAMIC_NODES
int8_t list_add_d_node(list_t *l, void *v)
{
	node_t *n = (node_t *)malloc(sizeof(node_t));
	return (!n) ? (-1) : (list_internal_add_node(l, v, l->n_elems, n));
}

int8_t list_add_d_pos_node(list_t *l, void *v, uint32_t pos)
{
	node_t *n = (node_t *)malloc(sizeof(node_t));
	return (!n) ? (-1) : (list_internal_add_node(l, v, pos, n));
}

uint8_t list_delete_d_node(list_t *l, void **v)
{
	node_t *fnode = NULL;
	list_internal_delete_node(l, v, (l->n_elems-1), &fnode);
	free(fnode);

	return 0;
}

uint8_t list_delete_d_pos_node(list_t *l, void **v, uint32_t pos)
{
	node_t *fnode = NULL;
	list_internal_delete_node(l, v, pos, &fnode);
	free(fnode);

	return 0;
}
#endif /* LIST_DYNAMIC_NODES */

#ifdef LIST_DEBUG 
void list_print_nodes_values(list_t *l)
{
	node_t * n = l->init;
	uint32_t i = 0;

	while(n)
	{
		printf("node_t: %d - Val: %d \n", i, *(int32_t *)n->data);
		n = n->next;
		i++;
	}
}
#endif /* LIST_DEBUG */
