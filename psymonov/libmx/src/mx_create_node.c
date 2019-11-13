#include "libmx.h"

t_paths *mx_create_node(int *path, int index)
{
    t_paths *node = (t_paths *)malloc(sizeof(t_paths));
    if (node == NULL)
        return NULL;

    node->path = (int*)malloc(sizeof(int) * (index + 1));
    node->path[index] = -1;
    for (int i = 0; i < index; i++) {
        node->path[i] = path[i];
    }
    node->next = NULL;

    return node;
}
