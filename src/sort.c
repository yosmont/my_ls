/*
** EPITECH PROJECT, 2017
** sort
** File description:
** sort function
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

char **str_swap(char **str, int i)
{
	char *new;

	new = str[i];
	str[i] = str[i + 1];
	str[i + 1] = new;
	return(str);
}

char **str_rev_bubble_sort(char **str, int size)
{
	int check = 0;

	for (int i = 0; i < (size - 1); i++)
		if (my_strcmp(str[i + 1], str[i]) > 0) {
			str = str_swap(str, i);
			check = 1;
		}
	if (check != 0)
		str = str_rev_bubble_sort(str, size);
	return(str);
}

char **str_bubble_sort(char **str, int size)
{
	int check = 0;
	
	for (int i = 0; i < (size - 1); i++)
		if (my_strcmp(str[i + 1], str[i]) < 0) {
			str = str_swap(str, i);
			check = 1;
		}
	if (check != 0)
		str = str_bubble_sort(str, size);
	return(str);
}

t_filedate *putin_filedate(char **all_name, int size, char *str)
{
	t_filedate *file = malloc(sizeof(t_filedate) * size);
	struct stat file_info;
	char *cpy;

	if (my_strlen(str) > 1 && str[0] == '.')
		str = my_strcat(str, "/");
	else
		str = "./";
	cpy = my_strdup(str);
	for (int i = 0; i < size; i++) {
		stat(my_strcat(cpy, all_name[i]), &file_info);
		cpy = my_strdup(str);
		file[i].name = all_name[i];
		file[i].date = file_info.st_mtime;
	}
	return(file);
}

char **str_time_bubble_sort(char **all_name, int size, char *str)
{
	t_filedate *sort_name = putin_filedate(all_name, size, str);
	t_filedate tmp;
	int check = 1;

	while (check != 0) {
		check = 0;
		for (int i = 0; i < (size - 1); i++) {
			if (sort_name[i].date < sort_name[i + 1].date) {
				tmp = sort_name[i];
				sort_name[i] = sort_name[i + 1];
				sort_name[i + 1] = tmp;
				check = 1;
			}
		}
	}
	for (int i = 0; i < size; i++)
		all_name[i] = sort_name[i].name;
	return(all_name);
}
