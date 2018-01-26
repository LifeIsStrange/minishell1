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
		call_prompt();
		args = str_to_array(get_next_line());
		if (!(args)) {
			return (WRITE_DEFINE(EXIT));
		} else if (!(*(args))) {
			free(args);
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
