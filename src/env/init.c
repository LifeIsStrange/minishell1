/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Initialise environment shell
*/

#include "env.h"

static int env_dup(char **dest, char **src, size_t n)
{
	if (!(*(src + n))) {
		return (true);
	}
	*(dest + n) = my_strdup(*(src + n));
	if (!(dest + n)) {
		return (false);
	}
	if (!(env_dup(dest, src, n + 1))) {
		free(*(dest + n));
	}
	return (true);
}

char **init_env(char **arge)
{
	char **shell_env = NULL;
	size_t length = 0;

	if (!(arge)) {
		length = 0;
	} else {
		length = env_length(arge);
	}
	shell_env = create_env(length);
	if (!(shell_env)) {
		return (NULL);
	}
	if (arge) {
		if (!(env_dup(shell_env, arge, 0))) {
			free(shell_env);
			return (NULL);
		}
	}
	return (shell_env);
}

void free_env(char **arge)
{
	char **tmp = arge;

	while (*(tmp)) {
		free(*(tmp));
		++(tmp);
	}
	free(arge);
}
