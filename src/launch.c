/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Launch binary
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include "minishell.h"

static void get_error_by_signal(int status)
{
	if (status == SIGSEGV) {
		WRITE_DEFINE(SEGMENTATION_FAULT);
	}
	if (status == SIGFPE) {
		WRITE_DEFINE(FLOATING_POINT);
	}
}

int launch_binary(char *path, char **args, char **arge)
{
	pid_t pid = fork();
	int w_status;

	if (pid == -1) {
		return (false);
	} else if (pid == 0) {
		if (!(execve(path, args, arge))) {
			WRITE_DEFINE(EXEC_FORMAT_ERROR);
		}
	} else {
		waitpid(0, &(w_status), 0);
		if (w_status == -1) {
			return (false);
		} else if (WIFSIGNALED(w_status)) {
			get_error_by_signal(WTERMSIG(w_status));
		}
	}
	return (true);
}
