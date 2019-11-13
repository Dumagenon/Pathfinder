#include "libmx.h"

t_edge *mx_create_edge(int dest)
{
    t_edge *node = (t_edge *)malloc(sizeof(t_edge));
    if (node == NULL)
        return NULL;

    node->dest = dest;
    node->next = NULL;

    return node;
}
