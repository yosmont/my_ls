/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** rework03
*/

#include "../include/myls.h"

int	my_put_nbr(int nb)
{
	int modulo;

	if (nb < 0) {
		my_putchar(45);
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			modulo = (nb % 10);
			nb = nb / 10;
			my_put_nbr(nb);
			my_putchar(48 + modulo);
		} else {
			my_putchar(48 + nb % 10);
		}
	}
}
