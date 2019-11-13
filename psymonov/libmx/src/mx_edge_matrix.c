#include "libmx.h"

static int **push_zero(int V) {
    int **res = (int**) malloc(sizeof(int*) * V);
    for(int i = 0; i < V; i++) {
        res[i] = (int*) malloc(sizeof(int) * V);
        for(int j = 0; j < V; j++) {
            res[i][j] = 0;
        }
    }
    return res;
}

static int get_index(char **words, char *word) {
    int i = 0;
    while (words[i]) {
        if (mx_strcmp(words[i], word) == 0) return i;
        i++;
    }
    return 0;
}

static int get_number(const char *str) {
	int index = mx_get_char_index(str, ',') + 1;
	return mx_atoi(&str[index]);
}

static void addEdge(t_graph *graph, int src, int dest) 
{ 
    // edge from src to dest.
    t_edge *node = mx_create_edge(dest); 
    node->next = graph->array[src].head; 
    graph->array[src].head = node; 
  
    //edge from dest to src also 
    node = mx_create_edge(src); 
    node->next = graph->array[dest].head; 
    graph->array[dest].head = node; 
}

int **mx_edge_matrix(char **arr, char **words, t_graph *graph, int V) {
    int **res = push_zero(V);
    for(int i = 1; arr[i]; i++) {
        char *one = first_word(arr[i]), *two = second_word(arr[i]);
        int num = get_number(arr[i]), indexOne = get_index(words, one),
            indexTwo = get_index(words, two);
        res[indexOne][indexTwo] = num;
        res[indexTwo][indexOne] = num;

        addEdge(graph, indexOne, indexTwo);
        mx_strdel(&one);
        mx_strdel(&two);
	}
    return res;
}
