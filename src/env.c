/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Environment's management
*/

#include "libstring.h"
#include "minishell.h"

size_t env_length(char **arge)
{
	char **tmp = arge;

	while (!(*(tmp))) {
		++(tmp);
	}
	return ((tmp - arge));
}

char **add_to_env(char **arge, char *key, char *value)
{
	printf("%d\n", env_length(arge));
}
char *get_env(char **arge, char *env, size_t env_len)
{
	while (*(arge)) {
		if (my_strncmp(*(arge), env, env_len - 1)) {
			++(arge);
			continue;
		}
		return (my_strdup(*(arge) + sizeof(ENV_PATH) - 1));
	}
	return (NULL);
}
