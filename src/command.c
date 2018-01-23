/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Run command
*/

#include "libstring.h"
#include "minishell.h"
#include "command.h"

command_t const LIST_COMMAND[] = {
	{"cd", cd_command},
	{"setenv", setenv_command}
};

static char *get_env(char **arge, char *args)
{
	while (*(arge)) {
		if (my_strncmp(*(arge), ENV_PATH, sizeof(ENV_PATH) - 1)) {
			++(arge);
			continue;
		}
		return (my_strdup(*(arge) + sizeof(ENV_PATH) - 1));
	}
	return (NULL);
}

static void print_al(char **args)
{
	while (*(args)) {
		printf(">%s<\n", *args);
		++(args);
	}
}

int launch_binary(char **args, char **arge)
{
	char **path = path_to_array(get_env(arge, ENV_PATH), *(args));

	print_al(path);
	if (!(path)) {
		WRITE_DEFINE(COMMAND_NOT_FOUND);
		return (true);
	}
	WRITE_DEFINE(COMMAND_NOT_FOUND);
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
	return (launch_binary(args, arge));
}
