/*
** EPITECH PROJECT, 2017
** recu
** File description:
** recursive flag function
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

char **dos_listing(char *str)
{
	struct dirent *dir;
	DIR *fd;
	char **dos_list;
	int size = 0;
	int tmp = 0;
	char *cpy;
	
	fd = opendir(str);
	if (fd == NULL)
		exit(84);
	dir = readdir(fd);
	while(dir) {
		size = (DT_DIR & dir->d_type && dir->d_name[0] != '.')
			? (size + 1) : size;
		dir = readdir(fd);
	}
	dos_list = malloc(sizeof(char*) * (size + 1));
	fd = opendir(str);
	dir = readdir(fd);
	while (dir) {
		if (DT_DIR & dir->d_type && dir->d_name[0] != '.') {
			cpy = my_strdup(str);
			cpy = my_strcat(cpy, "/");
			dos_list[tmp] = my_strcat(cpy, dir->d_name);
			tmp++;
		} else {
			dos_list[tmp] = NULL;
		}
		dir = readdir(fd);
	}
	dos_list[tmp] == NULL;
	return(dos_list);
}

void recu(char **dos, char *flag)
{
	char **dos_2;
	struct dirent *dir;
	int tmp = 0;
	
	for (int i = 0; dos[i] != NULL; i++) {
		dos_2 = dos_listing(dos[i]);
		my_putchar('\n');
		put_new_name(dos[i]);
		just_a_test(dos[i], flag);
		if (dos_2[0] != NULL) {
			recu(dos_2, flag);
		}
	}
}

void ls_recursivity(char **av, int ac, char *flag, int check)
{
	char **dos;

	if (check == 0) {
		dos = dos_listing(".");
		my_putstr(".:\n");
		just_a_test(".", flag);
		if (dos[0] != NULL)
			recu(dos, flag);
		exit(0);
	}
	for (int i = 0; i < ac; i++) {
		dos = dos_listing(av[i]);
		if (i > 0)
			my_putchar('\n');
		put_new_name(av[i]);
		just_a_test(av[i], flag);
		if (dos[0] != NULL)
			recu(dos, flag);
	}
}
