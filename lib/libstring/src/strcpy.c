/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** Strncpy
*/

#include <stddef.h>

void my_strcpy(char *dest, char const *src)
{
	while (*(src)) {
		*(dest) = *(src);
		++(dest);
		++(src);
	}
	*(dest) = '\0';
}

void my_strncpy(char *dest, char const *src, size_t n)
{
	*(dest + n) = '\0';
	while (n) {
		--(n);
		*(dest + n) = *(src + n);
	}
}
