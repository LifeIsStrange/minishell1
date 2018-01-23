/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** strdup - Duplicate a string
*/

#include <unistd.h>
#include <stdlib.h>
void my_strcpy(char *dest, char const *src);
size_t my_strlen(const char *str);

char *my_strdup(const char *str)
{
	size_t length = my_strlen(str);
	char *new_str = malloc(sizeof(char) * (length + 1));

	if (!(new_str)) {
		return (NULL);
	}
	my_strcpy(new_str, str);
	*(new_str + length) = '\0';
	return (new_str);
}
