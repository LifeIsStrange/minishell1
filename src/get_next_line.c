/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** C file
*/

#include "get_next_line.h"

static char buffer[READ_SIZE];

char *get_next_line(int fd)
{
	ssize_t read_value = read(fd, buffer, READ_SIZE);
	size_t length = read_value - 1;
	char *str = malloc(sizeof(*(str)) * length + 1);

	if (!(str)) {
		return (NULL);
	}
	strncpy(str, buffer, length);
	while (read_value == READ_SIZE) {
		read_value = read(fd, buffer, READ_SIZE);
		str = realloc(str, sizeof(*(str)) * (length + read_value + 1));
		strncpy(str, &(buffer[length]), read_value);
		length = length + read_value;
	}
	str[length] = 0;
	printf(">>%s<<\n", str);
	return (str);
}
