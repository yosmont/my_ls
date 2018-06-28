/*
** EPITECH PROJECT, 2017
** display
** File description:
** display function
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

void display_long(char **all_name, int size, char *flag, char *str)
{
	int len = my_strlen(str);
	char *tmp = "./";

	if (len > 1 && str[len - 1] != '/')
		str = my_strcat(str, "/");
	else if (len > 1)
		str = str;
	else
		str = "./";
	while (all_name[0][0] == '.') {
		all_name++;
		size--;
	}
	print_long(all_name, size, flag, str);
}

void display_standart(char **all_name, int size, char *flag)
{
	while (all_name[0][0] == '.') {
		all_name++;
		size--;
	}
	my_putstr(all_name[0]);
	for (int tmp = 1; tmp < size; tmp++) {
		if (all_name[tmp][0] != '.') {
			my_putchar('\n');
			my_putstr(all_name[tmp]);
		}
	}
	my_putchar('\n');
}

void display(char **all_name, int size, char *flag, char *str)
{
	if (flag[0] == '1')
		display_long(all_name, size, flag, str);
	else
		display_standart(all_name, size, flag);
}

void display_d(char **all_name, int size, char *flag, char *str)
{
	if (flag[0] == '1') {
		print_long(all_name, size, flag, str);
	} else {
		for (int i = 0; i < size; i++) {
			my_putstr(all_name[i]);
			my_putchar('\n');
		}
	}
}
