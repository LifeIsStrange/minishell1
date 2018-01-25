/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Built_in
*/

#include "libstring.h"
#include "minishell.h"

void cd_command(char **args, char **arge)
{
	char *env = NULL;

	if (*(args + 1)) {
		if (chdir(*(args + 1))) {
			my_putstr(*(args + 1));
			WRITE_DEFINE(DIRECTORY_NOT_FOUND);
		}
		return;
	}
	env = get_env(arge, ENV_HOME, sizeof(ENV_HOME) - 1);
	if (env) {
		if (chdir(env)) {
			WRITE_DEFINE(CD_WRONG_HOME_DIRECTORY);
		}
	} else {
		WRITE_DEFINE(CD_NO_HOME_DIRECTORY);
	}
}

int setenv_command(char **args, char **arge)
{
	printf("set env\n");
	return (1);
}
