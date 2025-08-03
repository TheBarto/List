#include "sorting.h"

int8_t mergeSort(list_t *l, int init, int end, compare_func func)
{
    if (!l/* || !func*/)
        return -1;

    if (init >= end)
        return -1;

    mergeSort(l, init, (((end-init)/2)+init), func);
    mergeSort(l, (((end-init)/2)+init+1), end, func);
    
    return merge(l, init, (init+1+((end-init)/2)), end, func);
}

int8_t merge(list_t *l, int init, int m, int end, compare_func func)
{
    uint32_t aux_i = init, aux_j = m;
    node_t *n1 = list_get_node(l, aux_i);
    node_t *n2 = list_get_node(l, aux_j);
    //Make a compare if m == end || i == m. It success, swap :)
    if((init+1) == end) {
        if((*func)(n1->data, n2->data) > 0)
            list_move_node_by_pos(l, aux_j, aux_i);
    } else {
        uint8_t flag = 0;
        if(end%2 == 0) {
            end++;
            flag = 1;
        }

        while((aux_i < m) && (aux_j < end) && (n1) && (n2)) {
            if((*func)(n1->data, n2->data) > 0) {
                n2=n2->next;
                list_move_node_by_pos(l, aux_j, aux_i);
                m++;
                aux_j++;
                if((aux_j == end) && 
                        (flag == 1))
                    break;
            } else {
                n1=n1->next;
            }
            aux_i++;
        }
    }

#if defined LIST_DEBUG
#include <stdio.h>
    printf("After merge iteration\n");
    print_node_list_value(l);
#endif
    
    return 0;
}

/*int8_t radixSort(list_t *l, compare_func* func)
{
    Queue ord[10];
    int_t cont = 0;

    while(cont < l->n_elems)
    {
        for(int32_t i = 0; i < l->n_elems; i++)
        {
            aux_pos = (*func)();
            if(aux_pos == -1)
                cont = 0;
            else
            {
                cont++;
                change_node_pos(aux_pos, node, &ord[pos]);
            }
        }
    }

    return 0;
}*/

