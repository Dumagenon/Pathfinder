#include "libmx.h"

static bool strcmp_my(int *arr1, int *arr2) {
    int i;
    for (i = 0; arr1[i] != -1 && arr1[i] == arr2[i]; i++);
    if (arr1[i] > arr2[i]) return true;
    return false;
}

static void swap_info(t_paths *tmp) {
    int *temp1 = tmp->path;
    tmp->path = tmp->next->path;
    tmp->next->path = temp1;
    int temp2 = tmp->weight;
    tmp->weight = tmp->next->weight;
    tmp->next->weight = temp2;
}

void mx_sort_paths(t_paths *lst) {
    if (lst == NULL) return;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (t_paths *tmp = lst; tmp->next; tmp = tmp->next)
        {
            if (strcmp_my(tmp->path, tmp->next->path) && tmp->weight == tmp->next->weight)
            {
                swap_info(tmp);
                flag = 1;
            }
        }
    }
}
