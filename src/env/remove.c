/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Remove key (and value) from environment
*/

#include "env.h"

static size_t get_key_index(char **arge, char *ptr)
{
	size_t index = 0;

	while (*(arge + index) != ptr) {
		++(index);
	}
	return (index);
}

static int delete_key(char ***arge, char *key_to_delete)
{
	char **tmp = *(arge);
	size_t index_node_delete = get_key_index(tmp, key_to_delete);
	size_t length = env_length(tmp);

	*(arge) = malloc(sizeof(char **) * (length));
	if (!(*(arge))) {
		return (false);
	}
	env_ncpy(*(arge), tmp, index_node_delete);
	env_cpy(*(arge) + index_node_delete, tmp + index_node_delete + 1);
	*(*(arge) + length - 1) = NULL;
	free(key_to_delete);
	free(tmp);
	return (true);
}

int rm_from_env(char ***arge, char *key)
{
	char **tmp = *(arge);

	if (!(tmp)) {
		return (true);
	}
	while (*(tmp)) {
		if (!(get_env(tmp, key))) {
			++(tmp);
			continue;
		}
		return (delete_key(arge, get_env(tmp, key)));
	}
	return (true);
}
