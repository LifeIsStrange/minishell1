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

// Environment
# define	ENV_PATH	"PATH"
# define	ENV_HOME	"HOME"
# define	ENV_PWD		"PWD"
# define	ENV_OLD_PWD	"OLDPWD"

// Built-in commmands
# define	CMD_EXIT	"exit"
# define	CMD_SETENV	"setenv"
# define	CMD_UNSETENV	"unsetenv"
# define	CMD_CD		"cd"
# define	CMD_ENV		"env"

// Signal
# define	FLOATING_SIGNAL		136
# define	SEGFAULT_SIGNAL		139
# define	SIGNAL_HANDLER		"^C"

# ifndef	READ_SIZE
#  define	READ_SIZE (2)
# endif		/* READ_SIZE */

// Prototypes
char *get_next_line(void);
char **str_to_array(char *str);
char **path_to_array(char *path, char *command);
char **init_env(char **arge);
void free_env(char **arge);
int add_to_env(char ***arge, char *key, char *value);
int delete_from_env(char ***arge, char *key);
int launch_command(char **args, char ***arge);
int launch_binary(char *path, char **args, char **arge);

char *get_pwd(void);

#endif		/* MINISHELL_H_ */
