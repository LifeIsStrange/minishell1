/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Main file
*/

#include "minishell.h"
#include <sys/types.h>
#include <stdio.h>


int main(int argc, char **argv, char **arge)
{
	char **args;
	char *s = 1;

	do {
		printf("%s", get_next_line(0));
//		args = my_str_to_word_array(get_next_line(0));
//		execve("/bin/ls", args, arge);
//		free(args);
	} while (s);
	return (0);
}
