/*
** EPITECH PROJECT, 2017
** main
** File description:
** file for main
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
#include "include/myls.h"

int main(int ac, char **av)
{
	char *flag;
	int first_file = 0;
	int check = 0;

	flag = detect_flag(ac, av, &first_file);
	if (first_file < ac) {
		av = av + first_file;
		check = 1;
	}
	ac = ac - first_file;
	if (flag[2] == '1')
		ls_d_flag(av, ac, flag, check);
	else if (flag[1] == '0')
		ls_no_recursivity(av, ac, flag);
	else
		ls_recursivity(av, ac, flag);
}
