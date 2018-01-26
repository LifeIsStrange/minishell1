/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Run command
*/

#include "minishell.h"
#include "libstring.h"
#include "command.h"
#include "env.h"

command_t const LIST_COMMAND[] = {
	{CMD_CD, cd_command},
	{CMD_ENV, env_command},
	{CMD_SETENV, setenv_command},
	{CMD_UNSETENV, unsetenv_command}
};

static int launch_binary_by_path(char **path, char **args, char **arge)
{
	while (*(path)) {
		if (access(*(path), F_OK)) {
			++(path);
			continue;
		}
		if (access(*(path), X_OK)) {
			my_puts(*(path));
			return (WRITE_DEFINE(EXEC_PERM_ERROR));
		}
		return (launch_binary(*(path), args, arge));
	}
	if (!(*(path))) {
		my_puts(*(args));
		WRITE_DEFINE(COMMAND_NOT_FOUND);
	}
	return (true);
}

static int launch_binary_by_command(char **args, char **arge)
{
	char *env = my_strdup(get_env(arge, ENV_PATH));
	char **path = path_to_array(env, *(args));

	if (!(env)) {
		my_puts(*(args));
		WRITE_DEFINE(COMMAND_NOT_FOUND);
		return (true);
	}
	if (!(path)) {
		return (false);
	}
	if (!(launch_binary_by_path(path, args, arge))) {
		free(*(path));
		free(path);
		return (false);
	}
	free(*(path));
	free(path);
	return (true);
}

static char *get_path_by_dir(char *dir, char *bin_name)
{
	size_t dir_length = my_strlen(dir);
	size_t bin_length = my_strlen(bin_name);
	char *path = malloc(sizeof(char) * (dir_length + bin_length + 1));

	if (!(path)) {
		return (NULL);
	}
	my_strcpy(path, dir);
	my_strcpy(path + dir_length, bin_name + 1);
	*(path + dir_length + bin_length) = '\0';
	return (path);
}

static int launch_binary_by_dir_command(char **args, char **arge)
{
	char *dir = get_pwd();
	char *path = NULL;

	if (!(dir)) {
		return (false);
	}
	path = get_path_by_dir(dir, *(args));
	if (!(path)) {
		free(dir);
		return (false);
	}
	if (!(launch_binary_by_path(&(path), args, arge))) {
		free(path);
		free(dir);
		return (false);
	}
	free(path);
	free(dir);
	return (true);
}

int launch_command(char **args, char ***arge)
{
	uint counter = 0;

	if (!(*(args))) {
		return (true);
	}
	do {
		if (my_strcmp(*(args), LIST_COMMAND[counter].cmd)) {
			continue;
		}
		return (LIST_COMMAND[counter].fptr(args, arge));
	} while (++(counter) < ARRAY_SIZE(LIST_COMMAND));
	if (*(*(args)) == '/') {
		return (launch_binary_by_path(&(*(args)), args, *(arge)));
	} else if (!(my_strncmp(*(args), "./", 2))) {
		return (launch_binary_by_dir_command(args, *(arge)));
	}
	return (launch_binary_by_command(args, *(arge)));
}
