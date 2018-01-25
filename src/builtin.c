/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Built_in
*/

#include "libstring.h"
#include "minishell.h"

int cd_command(char **args, char **arge)
{
	char *env = NULL;

	if (*(args + 1)) {
		if (chdir(*(args + 1))) {
			my_puts(*(args + 1));
			WRITE_DEFINE(DIRECTORY_NOT_FOUND);
		}
		return (true);
	}
	env = get_env(arge, ENV_HOME, sizeof(ENV_HOME) - 1);
	if (env) {
		if (chdir(env)) {
			WRITE_DEFINE(CD_WRONG_HOME_DIRECTORY);
		}
	} else {
		WRITE_DEFINE(CD_NO_HOME_DIRECTORY);
	}
	return (true);
}

int env_command(char **args, char **arge)
{
	while (*(arge)) {
		my_puts(*(arge));
		my_putchar('\n');
		++(arge);
	}
	return (true);
}

int setenv_command(char **args, char **arge)
{
	add_to_env(arge, *(args + 1), *(args + 2));
	printf("set env\n");
	return (1);
}

int unsetenv_command(char **args, char **arge)
{
	printf("unset env\n");
	return (1);
}
