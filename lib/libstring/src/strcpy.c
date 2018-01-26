/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** strcpy, strncpy - Copy a string
*/

#include <stddef.h>

void my_strcpy(char *dest, char const *src)
{
	if (src) {
		while (*(src)) {
			*(dest) = *(src);
			++(dest);
			++(src);
		}
		*(dest) = '\0';
	}
}

void my_strncpy(char *dest, char const *src, size_t n)
{
	if (src) {
		*(dest + n) = '\0';
		while (n) {
			--(n);
			*(dest + n) = *(src + n);
		}
	}
}
