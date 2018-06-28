/*
** EPITECH PROJECT, 2017
** precall
** File description:
** pre-call
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

void put_new_name(char *str)
{
	my_putstr(str);
	my_putstr(":\n");
}

void ls_no_recursivity(char **av, int ac, char *flag)
{
	if (ac > 1) {
		put_new_name(av[0]);
		just_a_test(av[0], flag);
		for (int i = 1; i < ac; i++) {
			my_putchar('\n');
			put_new_name(av[i]);
			just_a_test(av[i], flag);
		}
	} else if (ac == 1)
		just_a_test(av[0], flag);
	else
		just_a_test(".", flag);
}

void ls_d_flag(char **av, int ac, char *flag, int check)
{
	char **all_name;
	int size = 0;
	char *str = "../";
	
	if (check == 1) {
		all_name = malloc(sizeof(char*) * ac);
		for (int i = 0; i < ac; i++) {
			all_name[i] = av[i];
		}
		size = ac;
		all_name = sort(all_name, size, flag, str);
	} else {
		all_name = malloc(sizeof(char*));
		all_name[0] = malloc(sizeof(char) * 2);
		all_name[0] = ".\0";
		size = 1;
	}
	display_d(all_name, size, flag, str);
}
