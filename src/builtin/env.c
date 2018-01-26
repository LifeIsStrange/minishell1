/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Environment builtin
*/

#include "libstring.h"
#include "env.h"

int env_command(unused char **args, char ***arge)
{
	char **tmp = *(arge);

	while (*(tmp)) {
		my_puts(*(tmp));
		my_putchar('\n');
		++(tmp);
	}
	return (true);
}

int setenv_command(char **args, char ***arge)
{
	return (add_to_env(arge, *(args + 1), *(args + 2)));
}

int unsetenv_command(char **args, char ***arge)
{
	return (delete_from_env(arge, *(args + 1)));
}
