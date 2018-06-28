/*
** EPITECH PROJECT, 2017
** ls long
** File description:
** long function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/myls.h"

char type(struct stat file_info)
{
	switch (file_info.st_mode & S_IFMT) {
	case S_IFREG:
		return('-');
	case S_IFDIR:
		return('d');
	case S_IFBLK:
		return('b');
	case S_IFCHR:
		return('c');
	case S_IFIFO:
		return('f');
	case S_IFLNK:
		return('l');
	case S_IFSOCK:
		return('s');
	default:
		return('-');
	}
}

char *right_line(struct stat file_info)
{
	char *line;

	line = malloc(sizeof(char) * 11);
	line[0] = type(file_info);
	line[1] = (S_IRUSR & file_info.st_mode) ? 'r' : '-';
	line[2] = (S_IWUSR & file_info.st_mode) ? 'w' : '-';
	line[3] = (S_IXUSR & file_info.st_mode) ? 'x' : '-';
	line[4] = (S_IRGRP & file_info.st_mode) ? 'r' : '-';
	line[5] = (S_IWGRP & file_info.st_mode) ? 'w' : '-';
	line[6] = (S_IXGRP & file_info.st_mode) ? 'x' : '-';
	line[7] = (S_IROTH & file_info.st_mode) ? 'r' : '-';
	line[8] = (S_IWOTH & file_info.st_mode) ? 'w' : '-';
	line[9] = (S_IXOTH & file_info.st_mode) ? 'x' : '-';
	line[10] = '\0';
	return(line);
}

void putstrwithspace(char *str)
{
	my_putstr(str);
	my_putchar(' ');
}

int bytesmax(char **all_name, int size, char *str)
{
	struct stat file_info;
	int space = 0;
	char *cpy = my_strdup(str);
	int tot = 0;
	int nb = 4096 / 1024;
	int tot_by_file = 0;

	for(int i = 0; i < size; i++) {
		stat(my_strcat(cpy, all_name[i]), &file_info);
		cpy = my_strdup(str);
		if (my_nbrlen(file_info.st_size) > space)
			space = my_nbrlen(file_info.st_size);
		tot_by_file = (file_info.st_size + 4095) / 4096 * nb;
		tot = tot + tot_by_file;
	}
	my_putstr("total ");
	my_put_nbr(tot);
	my_putchar('\n');
	return(space);
}

void printspacebytes (struct stat file_info, int space)
{
	int total = space - my_nbrlen(file_info.st_size);

	for (int i = 0; i < total; i++)
		my_putchar(' ');
}
