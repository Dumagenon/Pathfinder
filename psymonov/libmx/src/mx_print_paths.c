#include "libmx.h"

static int get_end_index(int *path) {
    int res = 0;
    while(path[res] != -1) res++;
    return res - 1;
}

// Print Path
static void print_path(char *s1, char *s2) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(s1);
    mx_printstr(" -> ");
    mx_printstr(s2);
    mx_printchar('\n');
}

// Print Route
static void print_route(int *path, char **words) {
    mx_printstr("Route: ");
    for (int i = 0; path[i] != -1; i++) {
        if (path[i + 1] != -1) {
            mx_printstr(words[path[i]]);
            mx_printstr(" -> ");
        } else mx_printstr(words[path[i]]);
    }
    mx_printchar('\n');
}

// Print Distance
static void print_distance(int *path, int **matr) {
    mx_printstr("Distance: ");
    if (get_end_index(path) == 1) {
        mx_printint(matr[path[0]][path[1]]);
        mx_printchar('\n');
    } else {
        int sum = 0;
        for (int i = 0; path[i] != -1; i++) {
            if (path[i + 1] != -1) {
                sum += matr[path[i]][path[i + 1]];
                mx_printint(matr[path[i]][path[i + 1]]);
                if (path[i + 2] != -1)
                    mx_printstr(" + ");
            } else {
                mx_printstr(" = ");
                mx_printint(sum);
                mx_printchar('\n');
            }
        }
    }
    mx_printstr("========================================\n");
}

void mx_print_paths(int **matr, t_paths *paths, char **words) {
    for (t_paths *i = paths; i != NULL; i = i->next) {
        print_path(words[i->path[0]], words[i->path[get_end_index(i->path)]]);
        print_route(i->path, words);
        print_distance(i->path, matr);
    }
}
