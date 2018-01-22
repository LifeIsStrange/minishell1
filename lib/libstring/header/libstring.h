/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** Header file
*/

#ifndef		LIB_STRING_H
# define	LIB_STRING_H

#include <unistd.h>

size_t my_strcmp(char const *s1, char const *s2);
size_t my_strncmp(char const *s1, char const *s2, int n);
int my_atoi(char const *str);
ssize_t my_strchr(char *str, char c);
size_t my_strlen(const char *str);
void my_strcpy(char *dest, char const *src);
void my_strncpy(char *dest, char const *src, size_t n);

#endif		/* LIB_STRING_H */
