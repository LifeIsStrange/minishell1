/*
** EPITECH PROJECT, 2018
** LibString
** File description:
** Atoi - Convert a string to an integer
*/

#include <limits.h>

int my_atoi(char const *str)
{
	char sign = 1;
	long int nbr = 0;

	while (*str == '-' || *str == '+') {
		sign = ((*str++ == '-') ? -sign : sign);
	}
	while ('0' <= *str && *str <= '9') {
		nbr = nbr * 10 + *str++ - '0';
	}
	nbr = nbr * sign;
	return ((INT_MIN <= nbr && nbr <= INT_MAX) ? (int)nbr : 0);
}
