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
void env_ncpy(char **dest, char **src, size_t n);
char **create_env(size_t length);
char *get_env(char **arge, char *env);

int add_to_env(char ***arge, char *key, char *value);
int delete_from_env(char ***arge, char *key);

#endif		/* ENVIRONMENT_H_ */
