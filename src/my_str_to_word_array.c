/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Splits a string into words
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#define IS_CARAC(c)	(('!' <= c && c <= '~') ? true : false)

static inline char const *empty_string(char const *str)
{
	while (!(IS_CARAC(*(str)))) {
		if (!(*(str))) {
			break;
		}
		++(str);
	}
	return (str);
}

static char **malloc_tab(char const *str)
{
	char **tab;
	unsigned int word = 0;

	while (*(str)) {
		str = empty_string(str);
		while (IS_CARAC(*(str))) {
			++(str);
		}
		++(word);
	}
	tab = malloc(sizeof(char *) * (word + 1));
	tab[word] = NULL;
	return (tab);
}

static void malloc_word_tab(char const *str, char **tab)
{
	unsigned int word = 0;
	unsigned int count;

	while (*(str)) {
		str = empty_string(str);
		count = 0;
		while (IS_CARAC(*(str))) {
			++(count);
			++(str);
		}
		tab[word] = malloc(sizeof(char) * (count + 1));
		tab[word][count] = '\0';
		++(word);
	}
}

static void put_word_into_tab(char const *str, char **tab)
{
	unsigned int word = 0;
	unsigned int index;

	while (*(str)) {
		str = empty_string(str);
		index = 0;
		while (IS_CARAC(*(str))) {
			tab[word][index] = *(str);
			++(index);
			++(str);
		}
		++(word);
	}
}

char **my_str_to_word_array(char const *str)
{
	char **tab = malloc_tab(str);

	malloc_word_tab(str, tab);
	put_word_into_tab(str, tab);
	return (tab);
}
