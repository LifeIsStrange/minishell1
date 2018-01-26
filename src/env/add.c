/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Add key (and value) to environment
*/

#include "env.h"

static char *create_key_value(char const *key, char const *value)
{
	size_t key_length = my_strlen(key);
	size_t value_length = my_strlen(value);
	char *str = malloc(sizeof(char) * (key_length + value_length + 2));

	if (!(str)) {
		return (NULL);
	}
	my_strcpy(str, key);
	my_strcpy(str + key_length + 1, value);
	*(str + key_length) = '=';
	*(str + key_length + value_length + 1) = '\0';
	return (str);
}

static int add_key(char ***arge, char *key, char *value)
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

int add_to_env(char ***arge, char *key, char *value)
{
	if (!(key)) {
		return (env_command(NULL, *(arge)));
	}
	if (!(get_env(*(arge), key))) {
		return (add_key(arge, key, value));
	}
}
