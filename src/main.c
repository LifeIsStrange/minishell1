/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Main file
*/

#include "libstring.h"
#include "minishell.h"

static int loop_shell(char **arge)
{
	char **args;

	do {
		write(1, PROMPT, sizeof(PROMPT));
		args = str_to_array(get_next_line());
		if (!(launch_command(args, arge))) {
			return (false);
		}
		if (*(args) && !(my_strcmp(*(args), CMD_EXIT))) {
			free(*(args));
			free(args);
			break;
		}
		free(*(args));
		free(args);
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
