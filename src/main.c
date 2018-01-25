/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Main file
*/

#include "libstring.h"
#include "minishell.h"

static void call_prompt(void)
{
	WRITE_DEFINE(PROMPT);
}

static int is_user_exit(char **args)
{
	if (!(my_strcmp(*(args), CMD_EXIT))) {
		free(*(args));
		free(args);
		return (true);
	}
	return (false);
}

static int execute_command(char ***arge, char **args)
{
	if (!(my_strcmp(*(args), CMD_SETENV))) {
		add_to_env(arge, *(args + 1), *(args + 2));
	} else if (!(my_strcmp(*(args), CMD_UNSETENV))) {
		rm_from_env(arge, *(args + 1));
	}
	if (!(launch_command(args, *(arge)))) {
		return (false);
	}
	free(*(args));
	free(args);
	return (true);
}

static int loop_shell(char **arge)
{
	char **args = NULL;

	do {
		call_prompt();
		args = str_to_array(get_next_line());
		if (!(args)) {
			WRITE_DEFINE(EXIT);
			return (true);
		} else if (!(*(args))) {
			free(args);
			continue;
		}
		if (is_user_exit(args)) {
			return (true);
		}
		if (!(execute_command(&(arge), args))) {
			return (false);
		}
	} while (true);
	return (true);
}

int main(unused int argc, unused char **argv, char **arge)
{
	if (!(loop_shell(arge))) {
		return (84);
	}
	return (0);
}
