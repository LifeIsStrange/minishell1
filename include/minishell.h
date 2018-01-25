/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Header file
*/

#ifndef		MINISHELL_H_
# define	MINISHELL_H_

# include	"tools.h"

// Define
# define	ENV_PATH	"PATH="
# define	ENV_HOME	"HOME="
# define	CMD_EXIT	"exit"
# define	CMD_SETENV	"setenv"
# define	CMD_UNSETENV	"unsetenv"

// Signal
# define	FLOATING_SIGNAL	136
# define	SEGFAULT_SIGNAL	139

// Display
# define	PROMPT			"$> "
# define	EXIT			"exit\n"
# define	COMMAND_NOT_FOUND	": Command not found.\n"
# define	DIRECTORY_NOT_FOUND	": Not a directory\n"
# define	CD_NO_HOME_DIRECTORY	"cd: No home directory.\n"
# define	CD_WRONG_HOME_DIRECTORY	"cd: Can't change to home directory.\n"
# define	FD_NOT_RECIEVED		"Cannot recieve input\n"
# define	SEGMENTATION_FAULT	"Segmentation fault\n"
# define	FLOATING_POINT		"Floating exception\n"
# define	EXEC_FORMAT_ERROR	": Exec format error. \
Wrong Architecture\n"

# ifndef	READ_SIZE
#  define	READ_SIZE (3)
# endif		/* READ_SIZE */

// Prototypes
char *get_next_line(void);
char *get_env(char **arge, char *env, size_t env_len);
char **str_to_array(char *str);
char **path_to_array(char *path, char *command);
int launch_command(char **args, char **arge);

#endif		/* MINISHELL_H_ */
