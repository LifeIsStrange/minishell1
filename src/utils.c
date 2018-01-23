/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Utils file for minishell
*/

#include "libstring.h"
#include "minishell.h"

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
