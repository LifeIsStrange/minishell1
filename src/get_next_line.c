/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** C file
*/

#include <stdio.h>
#include "minishell.h"
static char buffer[READ_SIZE];

static inline ssize_t my_strchr(char *str)
{
	char *buffer = str;

	while (*(buffer)) {
		if (*(buffer) == '\n') {
			return ((buffer - str));
		}
		++(buffer);
	}
	return (-1);
}

static inline void my_strncpy(char *dest, char const *src, size_t n)
{
	*(dest + n) = 0;
	while (n) {
		--(n);
		*(dest + n) = *(src + n);
	}
}

static char *my_string(char *str, size_t size, size_t to_add)
{
	char *new_str = NULL;

	if (!(str)) {
		new_str = malloc(sizeof(char) * (to_add + 1));
		if (!(new_str)) {
			return (NULL);
		}
		my_strncpy(new_str, buffer, to_add - size);
	} else {
		new_str = malloc(sizeof(char) * (to_add + size + 1));
		if (!(new_str)) {
			return (NULL);
		}
		my_strncpy(new_str, str, size);
		my_strncpy(&(new_str[size]), buffer, to_add);
		free(str);
	}
	return (new_str);
}

char *get_next_line(void)
{
	char *line = NULL;
	int length = 0;
	int read_value = read(STDIN_FILENO, buffer, READ_SIZE);

	if (read_value == -1) {
		return (NULL);
	}
	while (my_strchr(buffer) == -1) {
		line = my_string(line, length, READ_SIZE);
		if (!(line)) {
			return (NULL);
		}
		length = length + READ_SIZE;
		read_value = read(STDIN_FILENO, buffer, READ_SIZE);
		if (read_value == -1) {
			return (NULL);
		}
	}
	return (my_string(line, length, my_strchr(buffer)));
}
