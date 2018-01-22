/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Main file
*/

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
/*
int try_fork(char **args, char **arge, char *path)
{
	int ret;
	pid_t pid = fork();

	if (pid == -1) {
		return (false);
	} else if (pid == 0) {
		execve(path, args, arge);
		exit(0);
	} else {
		waitpid(0, pid, 0);
	}
	return (true);
}

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
void print_all(char **args)
{
	while (*(args)) {
		printf(">%s<\n", *args);
		++(args);
	}
}

int main(int argc, char **argv, char **arge)
{
	char **args;
	char **path = NULL;
	char *s = 1;

	do {
		write(1, PROMPT, sizeof(PROMPT));
		args = str_to_array(get_next_line());
		if (!(args)) {
			return (84);
		}
		print_all(args);
//		path = get_possible_path(arge, *(args));
//		args = my_str_to_word_array(get_next_line(0));
//		if (path) {
//			printf("path: %s\n", *path);
//			try_fork(args, arge, path);
//			free(path);
//		}
//		printf("%p\n", args);
		if (*(args) && !(my_strcmp(*(args), "exit"))) {
			break;
		}
		free(*(args));
		free(args);
	} while (true);
	return (0);
}
