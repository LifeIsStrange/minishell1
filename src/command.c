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
	{"setenv", setenv_command},
	{"unsetenv", unsetenv_command}
};

static int get_error_by_signal(int w_status)
{
	if (WCOREDUMP(w_status)) {
		WRITE_DEFINE(SEGMENTATION_FAULT);
	}
}

static int launch_binary(char *path, char **args, char **arge)
{
	pid_t pid = fork();
	int w_status;

	if (pid == -1) {
		return (false);
	} else if (pid == 0) {
		return (execve(path, args, arge));
	} else {
		waitpid(0, &(w_status), 0);
		if (w_status == -1) {
			return (false);
		} else if (WIFSIGNALED(w_status)) {
			get_error_by_signal(w_status);
		}
	}
	return (true);
}

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

static int launch_binary_by_command(char **args, char **arge)
{
	char *env = get_env(arge, ENV_PATH, sizeof(ENV_PATH));
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
		LIST_COMMAND[counter].fptr(args, arge);
		return (true);
	} while (++(counter) < ARRAY_SIZE(LIST_COMMAND));
	if (*(*(args)) == '/') {
		return (launch_binary_by_path(&(*(args)), args, arge));
	}
	return (launch_binary_by_command(args, arge));
}
