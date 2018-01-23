/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Run command
*/

#include <sys/types.h>
#include <sys/wait.h>
#include "libstring.h"
#include "minishell.h"
#include "command.h"

command_t const LIST_COMMAND[] = {
	{"cd", cd_command},
	{"setenv", setenv_command}
};

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
	}
	return (true);
}

static char *get_env(char **arge, char *env, size_t env_len)
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
		WRITE_DEFINE(COMMAND_NOT_FOUND);
	}
	return (true);
}

static int launch_binary_by_command(char **args, char **arge)
{
	char *env = get_env(arge, ENV_PATH, sizeof(ENV_PATH));
	char **path = path_to_array(env, *(args));

	if (!(env)) {
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
		return ((LIST_COMMAND[counter].fptr)(args, arge));
	} while (++(counter) < ARRAY_SIZE(LIST_COMMAND));
	return (launch_binary_by_command(args, arge));
}
