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

void env_cpy(char **dest, char **src)
{
	size_t counter = 0;

	while (src + counter) {
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

char *create_key_value(char const *key, char const *value)
{
	size_t key_length = my_strlen(key);
	size_t value_length = my_strlen(value);
	char *str = malloc(sizeof(char) * (key_length + value_length + 2));

	if (!(str)) {
		return (NULL);
	}
	my_strcpy(str, key);
	my_strcpy(str + key_length, value);
	*(str + key_length - 1) = '=';
	*(str + key_length + value_length) = '\0';
	return (str);
}

char *get_env(char **arge, char *env, size_t env_len)
{
	while (*(arge)) {
		if (my_strncmp(*(arge), env, env_len)) {
			++(arge);
			continue;
		}
		return (*(arge));
	}
	return (NULL);
}
