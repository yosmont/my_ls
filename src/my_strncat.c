/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** rework30
*/

#include "../include/myls.h"

char	*my_strncat(char *dest, char const *src, int nb)
{
	int len;
	int tmp = 0;

	len = my_strlen(dest);
	while (src[tmp] != '\0' && tmp != nb) {
		dest[len] = src[tmp];
		len++;
		tmp++;
	}
	dest[len] = '\0';
	return(dest);
}
