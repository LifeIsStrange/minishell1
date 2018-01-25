/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Add key (and value) to environment
*/

#include "env.h"

int add_to_env(char ***arge, char *key, char *value)
{
	char **tmp = *(arge);
	size_t length = env_length(tmp);

	*(arge) = create_env(length + 1);
	if (!(*(arge))) {
		return (false);
	}
	*(*(arge) + length) = create_key_value(key, value);
	if (!(*(*(arge + length)))) {
		free(arge);
		return (false);
	}
	env_cpy(*(arge), tmp);
	free(tmp);
	return (true);
}
