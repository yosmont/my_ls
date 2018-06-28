/*
** EPITECH PROJECT, 2017
** sort two
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

char **str_rev_time_bubble_sort(char **all_name, int size, char *str)
{
	t_filedate *sort_name = putin_filedate(all_name, size, str);
	t_filedate tmp;
	int check = 1;

	while (check != 0) {
		check = 0;
		for (int i = 0; i < (size - 1); i++) {
			if (sort_name[i].date > sort_name[i + 1].date) {
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

char **sort(char **all_name, int size, char *flag, char *str)
{
	if (flag[4] == '1') {
		if (flag[3] == '1')
			all_name = str_rev_time_bubble_sort(all_name,size,str);
		else
			all_name = str_time_bubble_sort(all_name, size, str);
	} else
		if (flag[3] == '1')
			all_name = str_rev_bubble_sort(all_name, size);
		else
			all_name = str_bubble_sort(all_name, size);
	return(all_name);
}
