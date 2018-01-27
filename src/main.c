/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Main file
*/

#include <signal.h>
#include "libstring.h"
#include "minishell.h"

int signal_detected = 0;

static void signal_handler(unused int handler)
{
	signal(SIGINT, signal_handler);
	write(1, "\n", 1);
	signal_detected = 1;
}

static int is_user_exit(char **args)
{
	if (!(args)) {
		WRITE_DEFINE(EXIT);
		return (true);
	} else if (!(*(args))) {
		return (false);
	}
	if (!(my_strcmp(*(args), CMD_EXIT))) {
		free(*(args));
		free(args);
		return (true);
	}
	return (false);
}

static int execute_command(char ***arge, char **args)
{
	if (!(*(args))) {
		free(args);
		return (true);
	}
	if (!(launch_command(args, arge))) {
		free(*(args));
		free(args);
		return (false);
	}
	free(*(args));
	free(args);
	return (true);
}

static int loop_shell(char ***arge)
{
	char **args = NULL;

	do {
		WRITE_DEFINE(PROMPT);
		args = str_to_array(get_next_line());
		if (signal_detected) {
			signal_detected = 0;
			continue;
		}
		if (is_user_exit(args)) {
			return (true);
		} else if (!(execute_command(arge, args))) {
			return (false);
		}
	} while (true);
}

int main(unused int argc, unused char **argv, char **arge)
{
	char **shell_env = init_env(arge);

	signal(SIGINT, signal_handler);
	if (!(shell_env)) {
		return (84);
	}
	if (!(loop_shell(&(shell_env)))) {
		free_env(shell_env);
		return (84);
	}
	free_env(shell_env);
	return (0);
}
