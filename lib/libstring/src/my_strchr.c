/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** my_strchr
*/

#include <unistd.h>

ssize_t my_strchr(char const *str, char c)
{
	char const *tmp = str;

	while (*(tmp)) {
		if (*(tmp) == c) {
			return (tmp - str);
		}
		++(tmp);
	}
	return (-1);
}
