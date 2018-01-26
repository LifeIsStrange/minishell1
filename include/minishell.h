/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Header file
*/

#ifndef		MINISHELL_H_
# define	MINISHELL_H_

# include	"tools.h"
# include	"error.h"

// Define
# define	ENV_PATH	"PATH"
# define	ENV_HOME	"HOME"
# define	CMD_EXIT	"exit"
# define	CMD_SETENV	"setenv"
# define	CMD_UNSETENV	"unsetenv"

// Signal
# define	FLOATING_SIGNAL	136
# define	SEGFAULT_SIGNAL	139

# ifndef	READ_SIZE
#  define	READ_SIZE (3)
# endif		/* READ_SIZE */

// Prototypes
char *get_next_line(void);
char **str_to_array(char *str);
char **path_to_array(char *path, char *command);
char **init_env(char **arge);
void free_env(char **arge);
char **add_to_env(char ***arge, char *key, char *value);
int launch_command(char **args, char **arge);

#endif		/* MINISHELL_H_ */
