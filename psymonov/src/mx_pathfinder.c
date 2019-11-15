#include "libmx.h"

int main(int argc, char const *argv[])
{
	if (argc != 2) 
	{
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(1);
	}
	// Get info from file to string
	char *file = mx_file_to_str(argv[1]);
	// Number of vertices - now zero
	int vert = 0;
	// Return array of strings from our char file
	// and number of vertices
	char **fileInfo = mx_text_check(file, &vert);
	// Create graph struct
	t_graph *graph = mx_create_graph(vert);
	// Returns array of words (names of our vertices)
	char **words = mx_arr_of_words(fileInfo, vert);
	// Returns int array of matches
	int **matr = mx_edge_matrix(fileInfo, words, graph, vert);
	// Returns list structure with all possible paths and their weights
	t_tmp *temp = findAllPaths(vert, matr, graph);
	// Returns a list of all minimum paths
	t_paths *paths = mx_find_short_path(temp, vert);
	// Sorts paths with the same weights in ascending order.
	mx_sort_paths(paths);
	// Prints all paths
	mx_print_paths(matr, paths, words);
	return 0;
}
