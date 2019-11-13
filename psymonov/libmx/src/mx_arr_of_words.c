#include "libmx.h"

char *first_word(const char *str) {
	int index = mx_get_char_index(str, '-');
	return mx_strndup(str, index);
}

char *second_word(const char *str) {
	int idMin = mx_get_char_index(str, '-') + 1;
	int idCom = mx_get_char_index(str, ',');
	int len = idCom - idMin;
	return mx_strndup(&str[idMin], len);
}

static void mx_add_word(char **arr, char *str, int V) {
    int id = 0;

    while (arr[id] && mx_strlen(arr[id])) {
        if (mx_strcmp(arr[id], str) == 0) {
            mx_strdel(&str);
            return;
        }
        id++;
    }
    if (id >= V) {
        mx_printerr("error: invalid number of islands");
	 	exit(0);
    }
    arr[id] = str;
}

char **mx_arr_of_words(char **arr, int V) {
	char **res = (char**) malloc(sizeof(char*) * (V + 1));
    int idWord = 0;
	res[V] = NULL;
    for (int i = 0; i < V; i++) res[i] = "";

	for(int i = 1; arr[i]; i++) {
        mx_add_word(res, first_word(arr[i]), V);
        mx_add_word(res, second_word(arr[i]), V);
	}
    while (res[idWord] && mx_strlen(res[idWord])) idWord++;

    if (idWord < V) {
        mx_printerr("error: invalid number of islands");
	 	exit(0);
    }
    return res;
}
