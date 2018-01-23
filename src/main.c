/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Main file
*/

#include <sys/types.h>
#include <sys/wait.h>
#include "libstring.h"
#include "minishell.h"

int try_fork(char **args, char **arge, char *path)
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

/*
char *my_strcat(char *first, char *second)
{
	char *str = malloc(strlen(first) + strlen(second));

	if (!(str)) {
		return (NULL);
	}
	strcpy(str, first);
	strcat(str, second);
	return (str);
}

uint substr_count(char *str, char c)
{
	uint counter = 0;

	while (*(str)) {
		if (*(str) == c) {
			++(counter);
		}
		++(str);
	}
	return (counter);
}

size_t my_strchr(char *path)
{
	size_t counter = 0;

	while (*(path)) {
		if (path == ':') {
			return (counter);
		}
		++(path);
		++(counter);
	}
	return (counter);
}

char **get_list_paths(char *path, char *command)
{
	uint counter = substr_count(path, ':') + 1;
	char **list = malloc(sizeof(char *) * (counter + 1));
	size_t iny = 0;

	if (!(list)) {
		return (NULL);
	}
	while (counter) {
		*(list + counter) = malloc(sizeof(char) * (my_strchr(path) + strlen(command) + 1));
		if (!(*(list + counter))) {
			return (NULL);
		}
		iny = 0;
		while (*(path) && *(path) != ':') {
			(*(list + counter))[iny] = *(path);
			++(iny);
			++(path);
		}
		strcpy(&(*(list + counter))[iny], command);
		--(counter);
	}
	return (list);
}

char **get_possible_path(char **arge, char *command)
{
	while (*(arge)) {
		if (strncmp(*(arge), ARG_PATH, sizeof(ARG_PATH) - 1)) {
			++(arge);
			continue;
		}
		return (get_list_paths(&(*(arge))[sizeof(ARG_PATH)], command));
	}
	return (NULL);
}
*/

static int loop_shell(char **arge)
{
	char **args;

	do {
		write(1, PROMPT, sizeof(PROMPT));
		args = str_to_array(get_next_line());
		if (!(launch_command(args, arge))) {
			return (84);
		}
		if (*(args) && !(my_strcmp(*(args), CMD_EXIT))) {
			free(*(args));
			free(args);
			break;
		}
		free(*(args));
		free(args);
	} while (true);
	return (0);
}

int main(unused int argc, unused char **argv, char **arge)
{
	if (!(loop_shell(arge))) {
		return (84);
	}
	return (0);
}
