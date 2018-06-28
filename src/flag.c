/*
** EPITECH PROJECT, 2017
** flag
** File description:
** flag create function
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

char *that_flag(char av, char *res)
{
        char *flag = "lRdrt";

	for (int i = 0; i < 6; i++)
		if (flag[i] == av)
			res[i] = '1';
	return(res);
}

char *detect_flag(int ac, char **av, int *first_file)
{
	char *res;
	int size = 0;
	int i = 1;

	res = malloc(sizeof(char) * 5);
	for (int tmp = 0; tmp < 5; tmp++) {
		res[tmp] = '0';
	}
	for (i; i < ac && av[i][0] == '-'; i++) {
		for (int j = 1; av[i][j] != '\0'; j++) {
			res = that_flag(av[i][j], res);
			size++;
		}
	}
        *first_file = i;
	return (res);
}
