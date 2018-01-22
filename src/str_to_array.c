/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Splits statically a string into words
*/

#include "libstring.h"
#include "minishell.h"

static char *next_carac(char *str)
{
	while (IS_CARAC(*(str))) {
		++(str);
	}
	if (!(*(str))) {
		return (str);
	}
	*(str) = '\0';
	while (*(++(str)) && !(IS_CARAC(*(str))));
	return (str);
}

static char const **alloc_array(uint deep)
{
	char const **tab = malloc(sizeof(char const *) * (deep + 1));

	if (!(tab)) {
		return (NULL);
	}
	*(tab + deep) = NULL;
	return (tab);
}

static char const **get_next_word(char *str, uint deep)
{
	char const *end_of_word = next_carac(str);
	char const **tab = NULL;

	if (!(end_of_word - str)) {
		return (alloc_array(deep));
	}
	tab = get_next_word(end_of_word, deep + 1);
	if (!(tab)) {
		return (NULL);
	}
	*(tab + deep) = str;
	return (tab);
}

static char const *get_correct_str(char *str)
{
	char const *tmp = str;
	char const *new_str = NULL;

	while (!(IS_CARAC(*(tmp)))) {
		++(tmp);
	}
	if (!(*(tmp))) {
		return (str);
	}
	new_str = malloc(sizeof(char) * (my_strlen(tmp) + 1));
	if (!(new_str)) {
		return (NULL);
	}
	my_strcpy(new_str, tmp);
	free(str);
	return (new_str);
}

char const **str_to_array(char *str)
{
	if (!(str)) {
		return (NULL);
	}
	if (!(IS_CARAC(*(str)))) {
		str = get_correct_str(str);
		if (!(str)) {
			return (NULL);
		}
	}
	return (get_next_word(str, 0));
}
