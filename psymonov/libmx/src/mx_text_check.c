#include "libmx.h"

static bool mx_line_check(const char *str)
{
    int one = 0, two = 0, three = 0;
    while (mx_isalpha(str[one])) one++;
    if (one == 0 || str[one++] != '-') return false;
    two = one;
    while (mx_isalpha(str[two])) two++;
    if (one == two || str[two++] != ',') return false;
    three = two;
    while (mx_isdigit(str[three])) three++;
    if (str[three]) return false;
    return true;
}

char **mx_text_check(const char *s, int *V) {
	char **tmp = mx_strsplit(s, '\n');
    int i;
	for (i = 0; tmp[i]; i++) {
        if(i == 0)
            for (int j = 0; tmp[i][j]; j++) {
                if(!(mx_isdigit(tmp[0][j])))
                {
                    mx_printerr("error: line 1 isn't valid\n");
                    exit(1);
                }
            }
        else {
            if (mx_line_check(tmp[i]) == false) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" isn't valid\n");
                exit(1);
            }
        }
    }
    *V = mx_atoi(tmp[0]);
    return tmp;
}
