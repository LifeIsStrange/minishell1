/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** Header file
*/

#ifndef		LIB_STRING_H
# define	LIB_STRING_H

#include <unistd.h>

// put.c: putchar, puts - Output of characters and strings
int my_putchar(char c);
int my_puts(const char *str);

// strlen.c: strlen - Calculate the length of a string
size_t my_strlen(const char *str);

// strcpy.c: strcpy, strncpy - Copy a string
void my_strcpy(char *dest, char const *src);
void my_strncpy(char *dest, char const *src, size_t n);

// strdup.c: strdup - Duplicate a string
char *my_strdup(char const *str);

// strcmp.c: strcmp, strncmp - Compare two strings
size_t my_strcmp(char const *s1, char const *s2);
size_t my_strncmp(char const *s1, char const *s2, size_t n);

// strchr.c: strchr - Locate character in string
char *my_strchr(char const *str, char c);

// atoi.c: atoi - Convert a string to an integer
int my_atoi(char const *str);

#endif		/* LIB_STRING_H */
