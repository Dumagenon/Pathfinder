#include "libmx.h"

t_graph *mx_create_graph(int V) {
	t_graph *graph = (t_graph*) malloc(sizeof(t_graph));
	graph->V = V;
	graph->array = (t_listOfEdges*) malloc(sizeof(t_listOfEdges) * V);
	for (int i = 0; i < V; i++) {
		graph->array[i].head = NULL;
	}
	return graph;
}
