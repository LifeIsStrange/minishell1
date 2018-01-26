/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Environment's management header
*/

#ifndef		ENVIRONMENT_H_
# define	ENVIRONMENT_H_

# include	"tools.h"

size_t env_length(char **arge);
void env_cpy(char **dest, char **src);
char **create_env(size_t length);
char *get_env(char **arge, char *env);

#endif		/* ENVIRONMENT_H_ */
