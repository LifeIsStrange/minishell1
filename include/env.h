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
char *create_key_value(char const *key, char const *value);
char *get_env(char **arge, char *env, size_t env_len);

#endif		/* ENVIRONMENT_H_ */
