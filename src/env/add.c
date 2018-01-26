/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Add key (and value) to environment
*/

#include "libstring.h"
#include "error.h"
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

static int is_valid_key(char *str)
{
	while (*(str)) {
		if (!(IS_ALPHA(*(str)) || IS_NUM(*(str)))) {
			return (false);
		}
		++(str);
	}
	return (true);
}

static int change_key(char **arge, char *dest, char *key, char *value)
{
	char *str = create_key_value(dest, key);

	if (!(str)) {
		return (false);
	}
	while (*(arge)) {
		if (*(arge) != dest) {
			++(arge);
			continue;
		}
		free(*(arge));
		*(arge) = my_strdup(str);
		if (!(str)) {
			return (false);
		}
		return (true);
	}
	return (false);
}

int add_to_env(char ***arge, char *key, char *value)
{
	char *str = NULL;

	if (!(key)) {
		return (env_command(NULL, *(arge)));
	}
	if (!(is_valid_key(key))) {
		return (WRITE_DEFINE(ENV_ERROR_KEY));
	}
	str = get_env(*(arge), key);
	if (!(str)) {
		return (add_key(arge, key, value));
	}
	return (change_key(*(arge), str, key, value));
}
