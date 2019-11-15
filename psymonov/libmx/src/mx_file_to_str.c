#include "libmx.h"

char *mx_file_to_str(const char *file)
{
	if (!file) exit(1);

	char buf[1];
	int count = 0;

	int srcFile = open(file, O_RDONLY);
	if (srcFile < 0) {
		mx_printerr("error: file ");
		mx_printerr(file);
		mx_printerr(" doesn't exist\n");
		exit(1);
	}

	int c = read(srcFile, buf, 1);
	if (c <= 0) {
		mx_printerr("error: file ");
		mx_printerr(file);
		mx_printerr(" is empty\n");
		exit(1);
	}
		
	// Считаем кол-во символов в файле
	while (c > 0) {
		c = read(srcFile, buf, 1);
		count++;
	}
	close(srcFile);
	// Выделяем новую память с нужным кол-вом байт
	char *d = mx_strnew(count);
	if (!d) exit(1);
	
	srcFile = open(file, O_RDONLY);

	read(srcFile, d, count);
	close(srcFile);
	return d;
}
