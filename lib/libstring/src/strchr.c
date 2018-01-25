/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** strchr - Locate character in string
*/

#include <unistd.h>

char *my_strchr(char const *str, char c)
{
	while (*(str)) {
		if (*(str) == c) {
			return ((char *)str);
		}
		++(str);
	}
	return (NULL);
}
