/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Built_in
*/

#include "libstring.h"
#include "minishell.h"
#include "env.h"

static int change_pwd(char ***arge)
{
	char *pwd = get_pwd();
	char *old_pwd = get_env(*(arge), ENV_PWD) + sizeof(ENV_PWD);

	if (!(pwd)) {
		return (false);
	}
	if (old_pwd) {
		if (!(add_to_env(arge, ENV_OLD_PWD, old_pwd))) {
			free(pwd);
			return (false);
		}
	}
	if (!(add_to_env(arge, ENV_PWD, pwd))) {
		free(pwd);
		return (false);
	}
	free(pwd);
	return (true);
}

static int change_to_directory(char ***arge, char *path)
{
	char *str = NULL;

	if (!(my_strcmp(path,  "-"))) {
		str = get_env(*(arge), ENV_OLD_PWD);
		if (!(str)) {
			return (WRITE_DEFINE(EMPTY_DIRECTORY_STACK));
		}
		return (change_to_directory(arge, str + sizeof(ENV_OLD_PWD)));
	}
	if (chdir(path)) {
		my_puts(path);
		return (WRITE_DEFINE(DIRECTORY_NOT_FOUND));
	}
	return (change_pwd(arge));
}

static int change_to_home(char ***arge)
{
	char *home = get_env(*(arge), ENV_HOME);

	if (!(home)) {
		return (WRITE_DEFINE(CD_NO_HOME_DIRECTORY));
	}
	if (chdir(home + sizeof(ENV_HOME))) {
		return (WRITE_DEFINE(CD_WRONG_HOME_DIRECTORY));
	}
	return (change_pwd(arge));
}

int cd_command(char **args, char ***arge)
{
	if (*(args + 1)) {
		return (change_to_directory(arge, *(args + 1)));
	}
	return (change_to_home(arge));
}
