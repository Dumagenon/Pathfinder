#include "libmx.h"

static t_paths *create_node(int *path, int weight)
{
    t_paths *node = (t_paths *)malloc(sizeof(t_paths));
    if (node == NULL)
        return NULL;

    node->path = path;
    node->weight = weight;
    node->next = NULL;

    return node;
}

static void push(t_paths **list, int *path, int weight)
{
    if (*list == NULL) {
        t_paths *node = create_node(path, weight);
        *list = node;
    } else {
        t_paths *node = create_node(path, weight), *p = *list;
        while (p->next)
            p = p->next;
        p->next = node;
    }
}

t_paths *mx_find_short_path(t_tmp *temp, int V) {
    t_paths *res = NULL;
    int num = 2147483647;
    for (int i = 0, d = V - 1; i < V - 1; i++, d--) {
        for (int c = 0; c < d; c++) {
            for (t_paths *j = temp->array[i].tale[c].head; j != NULL; j = j->next) {
                if (j->weight < num) num = j->weight;
            }
            for (t_paths *v = temp->array[i].tale[c].head; v != NULL; v = v->next) {
                if (v->weight == num)
                    push(&res, v->path, num);
            }
            num = 2147483647;
        }
    }
    return res;
}
