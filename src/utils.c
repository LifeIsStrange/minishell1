/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Get current directory
*/

#include "minishell.h"

char *get_pwd(void)
{
	char *str = NULL;
	size_t length = 0;

	do {
		if (str) {
			free(str);
		}
		length = length + READ_SIZE;
		str = malloc(sizeof(char) * length);
		if (!(str)) {
			return (NULL);
		}
	} while (!(getcwd(str, length)));
	return (str);
}
