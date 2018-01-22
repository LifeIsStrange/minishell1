/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Header file
*/

#ifndef		MINISHELL_H_
# define	MINISHELL_H_

# include	"tools.h"

# define	ARG_PATH	"PATH="
# define	PROMPT		"$>"

# define	IS_CARAC(c)	(('!' <= c && c <= '~') ? true : false)

# ifndef	READ_SIZE
#  define	READ_SIZE (3)
# endif		/* READ_SIZE */

char const **str_to_array(char *str);
char *get_next_line(void);

#endif		/* MINISHELL_H_ */
