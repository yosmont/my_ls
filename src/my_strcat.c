/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** rework29
*/

#include "../include/myls.h"

char	*my_strcat(char *dest, char const *src)
{
	int len;
	int tmp = 0;

	len = my_strlen(dest);
	while (src[tmp] != '\0') {
		dest[len] = src[tmp];
		len++;
		tmp++;
	}
	dest[len] = '\0';
	return(dest);
}
