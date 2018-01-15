/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** my_strncpy
*/

#include <stddef.h>

void my_strncpy(char *dest, char const *src, size_t n)
{
	*(dest + n) = 0;
	while (n) {
		--(n);
		*(dest + n) = *(src + n);
	}
}
