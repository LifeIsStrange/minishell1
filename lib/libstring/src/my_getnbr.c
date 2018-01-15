/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Created by lafeyc_v
*/

#include <limits.h>

int my_getnbr(char const *str)
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
