/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** my_strncmp
*/

#include <unistd.h>

size_t my_strncmp(char const *s1, char const *s2, int n)
{
	unsigned char c1;
	unsigned char c2;

	while (n > 0) {
		c1 = (unsigned char) *(s1++);
		c2 = (unsigned char) *(s2++);
		if (!(c1) || c1 != c2) {
			return (c1 - c2);
		}
		--(n);
	}
	return (c1 - c2);
}
