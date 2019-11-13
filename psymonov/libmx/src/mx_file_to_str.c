#include "libmx.h"

char *mx_file_to_str(const char *file)
{
	if (!file) {
		mx_printerr("error");
		exit(0);
	}

	char buf[1];
	int count = 0;

	int srcFile = open(file, O_RDONLY);
	if (srcFile < 0)
	{
		mx_printerr("error: file ");
		mx_printerr(file);
		mx_printerr(" doesn't exist");
		exit(0);
	}

	int c = read(srcFile, buf, 1);
	if (c <= 0)
	{
		mx_printerr("error: file ");
		mx_printerr(file);
		mx_printerr(" is empty");
		exit(0);
	}
		
	// Считаем кол-во символов в файле
	while (c > 0)
	{
		c = read(srcFile, buf, 1);
		count++;
	}
	close(srcFile);
	// Выделяем новую память с нужным кол-вом байт
	char *d = mx_strnew(count);
	if (!d)
	{
		mx_printerr("error");
		exit(0);
	}
	
	srcFile = open(file, O_RDONLY);

	read(srcFile, d, count);
	close(srcFile);
	return d;
}
