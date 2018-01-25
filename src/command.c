/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Run command
*/

#include "minishell.h"
#include "command.h"

command_t const LIST_COMMAND[] = {
	{"cd", cd_command},
	{"env", env_command},
};

static int launch_binary_by_path(char **path, char **args, char **arge)
{
	while (*(path)) {
		if (access(*(path), F_OK)) {
			++(path);
			continue;
		}
		return (launch_binary(*(path), args, arge));
	}
	if (!(*(path))) {
		my_puts(*(args));
		WRITE_DEFINE(COMMAND_NOT_FOUND);
	}
	return (true);
}

static int launch_binary_by_dir_command(char **args, char **arge)
{
}


static void get_error_by_signal(int w_status)
{
	if (w_status == SEGFAULT_SIGNAL) {
		WRITE_DEFINE(SEGMENTATION_FAULT);
	}
	if (w_status == FLOATING_SIGNAL) {
		WRITE_DEFINE(FLOATING_POINT);
	}
}

static int launch_binary_by_command(char **args, char **arge)
{
	char *env = my_strdup(get_env(arge, ENV_PATH, sizeof(ENV_PATH) - 1));
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

int launch_command(char **args, char **arge)
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
		return (launch_binary_by_path(&(*(args)), args, arge));
	} else if (!(my_strncmp(*(args), "./", 2))) {
		return (launch_binary_by_dir_command(args, arge));
	}
	return (launch_binary_by_command(args, arge));
}
