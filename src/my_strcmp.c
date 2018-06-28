/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** task05
*/

int	my_strcmp(char const *s1, char const *s2)
{
	int return_val;
	int tmp;

	tmp = 0;
	while (s1[tmp] == s2[tmp]) {
		if (s1[tmp] == '\0' && s2[tmp] == '\0') {
			return(0);
		}
		tmp++;
	}
	return_val = s1[tmp] - s2[tmp];
	return(return_val);
}
