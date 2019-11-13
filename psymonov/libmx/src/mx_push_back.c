#include "libmx.h"

void mx_push_back(t_paths **list, int *path, int index)
{
    if (*list == NULL) {
        t_paths *node = mx_create_node(path, index);
        *list = node;
    } else {
        t_paths *node = mx_create_node(path, index), *p = *list;
        while (p->next)
            p = p->next;
        p->next = node;
    }
}
