/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** putchar, putstr - Output of characters and strings
*/

#include <unistd.h>
size_t my_strlen(char const *str);

int my_putchar(char c)
{
	return (write(1, &c, 1));
}

int my_puts(char const *str)
{
	return (write(1, str, my_strlen(str)));
}
