/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Splits statically a env_path into word_path_dir
*/

#include "libstring.h"
#include "minishell.h"
#define IS_NOT_SEPARATOR(c)	(c - ':')
static char *cmd;

static char *next_carac(char *str)
{
	while (*(str) && IS_NOT_SEPARATOR(*(str))) {
		++(str);
	}
	if (!(*(str))) {
		return (str);
	}
	*(str) = '\0';
	while (*(++(str)) && !(IS_NOT_SEPARATOR(*(str))));
	return (str);
}

static char **alloc_array(size_t len, uint deep)
{
	char **tab = malloc(sizeof(char *) * (deep + 1));
	size_t length = len + (deep * (my_strlen(cmd) + 1)) + 1;

	if (!(tab)) {
		return (NULL);
	}
	*(tab) = malloc(sizeof(char) * (length));
	if (!(*(tab))) {
		free(tab);
		return (NULL);
	}
	*(tab + deep) = NULL;
	return (tab);
}

static void set_path_tab(char **tab, char *str, size_t len, uint deep)
{
	char * path_start = *(tab) + len + (my_strlen(cmd) + 1) * deep;
	size_t str_length = my_strlen(str);

	*(tab + deep) = path_start;
	strcpy(path_start, str);
	strcpy(path_start + str_length + 1, cmd);
	*(path_start + str_length) = '/';
}

static char **get_next_dir(char *str, size_t len, uint deep)
{
	char **tab = NULL;
	size_t path_len = next_carac(str) - str;

	if (!(path_len)) {
		return (alloc_array(len, deep));
	}
	tab = get_next_dir(str + path_len, len + path_len, deep + 1);
	if (!(tab)) {
		return (NULL);
	}
	set_path_tab(tab, str, len, deep);
	return (tab);
}

char **path_to_array(char *path, char *command)
{
	if (!(path)) {
		return (NULL);
	}
	cmd = command;
	return (get_next_dir(path, 0, 0));
}
