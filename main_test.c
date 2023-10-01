#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    List l;

    assert(init_list(&l));

    int a[5] = {456, -43, 0, 1234, 98176};
    assert(add_value(&l, (void *)&a[0], 0) == 0);
    assert(add_value(&l, (void *)&a[4], 0) == 0);
    assert(add_value(&l, (void *)&a[2], 0) == 0);
    assert(add_value(&l, (void *)&a[1], 0) == 0);
    
    assert(get_total_nodes(&l) == 4);

    int aux[5] = {};
    assert(get_value(&l, (void *)&aux[0], 3) == 0);
    assert(aux[0] == a[1]);
    assert(get_value(&l, (void *)&aux[1], 1) == 0);
    assert(aux[1] == a[4]);
    assert(get_value(&l, (void *)&aux[2], 0) == 0);
    assert(aux[2] == a[0]);
    assert(get_value(&l, (void *)&aux[3], 2) == 0);
    assert(aux[3] == a[2]);
    
    assert(delete_node(&l, (void *)&aux[0], 3) == 0);
    assert(aux[0] == a[1]);
    assert(delete_node(&l, (void *)&aux[0], 1) == 0);
    assert(aux[3] == a[4]);
    assert(delete_node(&l, (void *)&aux[0], 0) == 0);
    assert(aux[3] == a[0]);
    assert(delete_node(&l, (void *)&aux[0], 0) == 0);
    assert(aux[3] == a[2]);

    return EXIT_SUCCESS;
}
