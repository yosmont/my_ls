/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** rework05
*/

#include "../include/myls.h"

int my_putstr(char const *str)
{
	int aff;
	int len;

	len = 0;
	aff = 0;
	while (str[len] != '\0') {
		len++;
	}
	while (aff < len) {
		my_putchar(str[aff]);
		aff++;
	}
}
