/*
** EPITECH PROJECT, 2017
** just a test
** File description:
** it's not a test...
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

void just_a_test(char *str, char *flag)
{
	struct dirent *dir;
	DIR *fd;
	int size = 0;
	char **all_name;

	fd = opendir(str);
	if (fd == NULL)
		exit(84);
	dir = readdir(fd);
	for (size; dir; size++)
		dir = readdir(fd);
	all_name = malloc(sizeof(char*) * size);
	fd = opendir(str);
	dir = readdir(fd);
	for (int tmp = 0; dir; tmp++, dir = readdir(fd)) {
		all_name[tmp] = dir->d_name;
	}
        all_name = sort(all_name, size, flag, str);
	display(all_name, size, flag, str);
}
