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

	while (*(tmp)) {
		++(tmp);
	}
	return ((tmp - arge));
}

void env_ncpy(char **dest, char **src, size_t n)
{
	while (n) {
		--(n);
		*(dest + n) = *(src + n);
	}
}

void env_cpy(char **dest, char **src)
{
	size_t counter = 0;

	while (*(src + counter)) {
		*(dest + counter) = *(src + counter);
		++(counter);
	}
}

char **create_env(size_t length)
{
	char **env = malloc(sizeof(char **) * (length + 1));

	if (!(env)) {
		return (NULL);
	}
	*(env + length) = NULL;
	return (env);
}

char *get_env(char **arge, char *env)
{
	size_t length = my_strlen(env);

	while (*(arge)) {
		if (my_strncmp(*(arge), env, length)) {
			++(arge);
			continue;
		}
		if (*(*(arge) + length) != '=') {
			++(arge);
			continue;
		}
		return (*(arge));
	}
	return (NULL);
}
