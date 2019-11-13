#include "libmx.h"

static t_tmp *create_struct(int V) {
    t_tmp *temp = (t_tmp*) malloc(sizeof(t_tmp));
    temp->visited = (int*) malloc(sizeof(int) * V); 
    temp->path = (int*) malloc(sizeof(int) * V);
    temp->array = (t_tale*) malloc(sizeof(t_tale) * V - 1);
    temp->when = 0;
    for (int i = 0, j = 1; i < V; i++, j++)
        temp->array[i].tale = (t_head*) malloc(sizeof(t_head) * (V - j));
    for (int i = 0, d = V - 1; i < V; i++, d--) 
        for (int j = 0; j < d; j++) 
		    temp->array[i].tale[j].head = NULL;
    return temp;
}

static void count_weight(t_tmp *temp, int **matrix, int V) {
    for (int i = 0, d = V - 1; i < V; i++, d--) {
        for (int z = 0; z < d; z++) {
            for (t_paths *j = temp->array[i].tale[z].head; j != NULL; j = j->next) {
                for (int c = 0; j->path[c + 1] != -1; c++) {
                    j->weight += matrix[j->path[c]][j->path[c + 1]];
                }
            }
        }
    }
}

static void findAllPathsUtil(int u, int d, int *path_index, t_tmp *temp, t_graph *graph) 
{ 

    temp->visited[u] = 1; 
    temp->path[(*path_index)] = u; 
    (*path_index)++;
   
    if (u == d)
        mx_push_back(&temp->array[temp->vers].tale[temp->when].head, temp->path, (*path_index));
    else { 
        for (t_edge *i = graph->array[u].head; i != NULL; i = i->next) 
            if (!temp->visited[i->dest]) 
                findAllPathsUtil(i->dest, d, path_index, temp, graph); 
    } 
    (*path_index)--; 
    temp->visited[u] = 0; 
} 

t_tmp *findAllPaths(int V, int **matrix, t_graph *graph) 
{ 
    t_tmp *temp = create_struct(V);

    int path_index = 0; 

    for (int z = 0; z < V; z++) temp->visited[z] = 0;

    for(int i = 0; i < V; i++) {
        temp->vers = i;
        for (int j = i + 1; j < V; j++) {
            findAllPathsUtil(i, j, &path_index, temp, graph);
            (temp->when)++;
        }  
        temp->when = 0;
    }
    count_weight(temp, matrix, V);
    return temp;
} 
