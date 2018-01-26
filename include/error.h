/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Error
*/

#ifndef		MINISHELL_ERROR_H_
# define	MINISHELL_ERROR_H_

# define	PROMPT			"$> "
# define	EXIT			"exit\n"
# define	COMMAND_NOT_FOUND	": Command not found.\n"
# define	DIRECTORY_NOT_FOUND	": Not a directory.\n"
# define	EMPTY_DIRECTORY_STACK	"cd: No such entry in dir stack\n"
# define	CD_NO_HOME_DIRECTORY	"cd: No home directory.\n"
# define	CD_WRONG_HOME_DIRECTORY	"cd: Can't change to home directory.\n"
# define	FD_NOT_RECIEVED		"Cannot recieve input\n"
# define	SEGMENTATION_FAULT	"Segmentation fault\n"
# define	FLOATING_POINT		"Floating exception\n"
# define	EXEC_PERM_ERROR		": Permission denied.\n"
# define	EXEC_FORMAT_ERROR	": Exec format error. \
Wrong Architecture.\n"
# define	ENV_ERROR_KEY		"setenv: Variable name must contain \
alphanumeric characters.\n"

#endif		/* MINISHELL_ERROR_H_ */
