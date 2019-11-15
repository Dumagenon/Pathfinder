#ifndef LIBMX_H
#define LIBMX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <fcntl.h>
#include <string.h>
#include <malloc/malloc.h>

typedef struct s_paths {
	int *path;
	int weight;
	struct s_paths *next;
} t_paths;

typedef struct s_head {
	struct s_paths *head;
} t_head;

typedef struct s_tale {
	struct s_head *tale;
} t_tale;

typedef struct s_tmp {
	int *visited;
	int *path;
	int vers;
	int when;
	struct s_tale *array;
} t_tmp;

typedef struct s_listOfEdge {
	int dest;
	struct s_listOfEdge *next;
} t_edge;

typedef struct s_listOfLists {
	struct s_listOfEdge *head;
} t_listOfEdges;

typedef struct s_graph {
	int V;
	struct s_listOfLists *array;
} t_graph;

// Utils pack:
void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_printint(int n);

// String pack:
int mx_strlen(const char *s);
void mx_strdel(char **str);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char **mx_strsplit(const char *s, char c);
char *mx_file_to_str(const char *file);
char *mx_itoa(int number);

// List pack:
t_edge *mx_create_edge(int dest);
t_paths *mx_create_node(int *path, int index);
void mx_push_back(t_paths **list, int *path, int index);

//My function
bool mx_isspace(char c);
void mx_printerr(const char *s);
char **mx_text_check(const char *s, int *V);
bool mx_isdigit(char c);
bool mx_isalpha(int c);
int mx_atoi(const char *str);
char *first_word(const char *str);
char *second_word(const char *str);
char **mx_arr_of_words(char **arr, int V);
int **mx_edge_matrix(char **arr, char **words, t_graph *graph, int V);
t_graph *mx_create_graph(int V);
t_tmp *findAllPaths(int V, int **matrix, t_graph *graph);
t_paths *mx_find_short_path(t_tmp *temp, int V);
void mx_sort_paths(t_paths *lst);
void mx_print_paths(int **matr, t_paths *paths, char **words);

#endif
