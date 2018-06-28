/*
** EPITECH PROJECT, 2017
** ls long two
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

char *modification_date(struct stat file_info)
{
	char *date = ctime(&file_info.st_mtime) + 4;
	char *res;

	res = malloc(sizeof(char) * 10);
	res[0] = ' ';
	res[1] = '\0';
	res = my_strncat(res, date, 12);
	return(res);
}

void print_long(char **all_name, int size, char *flag, char *str)
{
	struct stat file_info;
	char *cpy = my_strdup(str);
	int space = bytesmax(all_name, size, str);
	
	for(int i = 0; i < size; i++) {
		if (all_name[i][0] != '.') {
			stat(my_strcat(cpy, all_name[i]), &file_info);
			cpy = my_strdup(str);
			putstrwithspace(right_line(file_info));
			my_put_nbr(file_info.st_nlink);
			my_putchar(' ');
			putstrwithspace(getpwuid(file_info.st_uid)->pw_name);
			putstrwithspace(getpwuid(file_info.st_gid)->pw_name);
			printspacebytes(file_info, space);
			my_put_nbr(file_info.st_size);
			putstrwithspace(modification_date(file_info));
			my_putstr(all_name[i]);
			my_putchar('\n');
		}
	}
}
