/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** strlen - Calculate the length of a string
*/

#include <unistd.h>

size_t my_strlen(const char *str)
{
	const char *tmp = str;

	if (!(*(tmp))) {
		return (0);
	}
	while (*(tmp)) {
		++(tmp);
	}
	return ((size_t) (tmp - str));
}
