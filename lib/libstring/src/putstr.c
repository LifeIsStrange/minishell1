/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** putstr - Put a string
*/

#include <unistd.h>
size_t my_strlen(const char *str);

int my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
}
