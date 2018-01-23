/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Command utils
*/

#ifndef		COMMAND_H_
# define	COMMAND_H_

typedef struct command_s command_t;

#ifndef WCOREDUMP
# define WCOREDUMP(status)	((status) & 0x80)
#endif

struct command_s {
	char *cmd;
	int (*fptr)(char **args, char **arge);
};

int cd_command(char **args, char **arge);
int setenv_command(char **args, char **arge);

#endif		/* COMMAND_H_ */
