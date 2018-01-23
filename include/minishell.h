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
# define	PROMPT		"$> "
# define	CMD_EXIT	"exit"

// Display
# define	COMMAND_NOT_FOUND	"Command not found\n"
# define	FD_NOT_POSSIBLE		"Cannot recieve input\n"

# ifndef	READ_SIZE
#  define	READ_SIZE (3)
# endif		/* READ_SIZE */

// Prototypes
char **str_to_array(char *str);
char *get_next_line(void);
int launch_command(char **args, char **arge);

#endif		/* MINISHELL_H_ */
