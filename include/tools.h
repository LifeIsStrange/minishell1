/*
** EPITECH PROJECT, 2018
** Tools
** File description:
** Header's Tools
*/

#ifndef		TOOLS_H_
# define	TOOLS_H_

# include	<stdbool.h>
# include	<stddef.h>
# include	<stdlib.h>
# include	<unistd.h>

# define	uint		unsigned int
# define	uchar		unsigned char

# define WRITE_DEFINE(str)	write(1, (str), sizeof((str)))

# define MIN(x, y)		(((x) < (y)) ?  (x) : (y))
# define MAX(x, y)		(((x) > (y)) ?  (x) : (y))
# define UPPER(x, max)		(((x) > (max)) ? (max) : (x))
# define LOWER(x, min)		(((x) < (min)) ? (min) : (x))

# define IS_ODD(x)		((x) & 1)
# define IS_EVEN(x)		(!IS_ODD((x)))

# define ABS(x)			(((x) < 0) ? -(x) : (x))
# define IS_NEG(x)		((x) == ABS((x)) ? 0 : 1)
# define DIFF(a, b)		ABS((a) - (b))

# define STMT(stuff)		do { (stuff) } while (0)

# define SWAP(a, b)		STMT(a ^= b; b ^= a; a ^= b;)
# define SORT(a, b)		STMT(if ((a) > (b)) SWAP((a), (b));)

# define SATINC(i, sat)		(i = (((i) == (sat)) ? (i) : ((i) + 1)))
# define SATDEC(i, sat)		(i = (((i) == (sat)) ? (i) : ((i) - 1)))

# define ARRAY_SIZE(a)		(sizeof(a) / sizeof((a)[0]))

# define BIT_SET(value, bit_index)	value |= (1 << (bit_index))
# define BIT_CLEAR(value, bit_index)	value &= ~(1 << (bit_index))
# define BIT_TOGGLE(value, bit_index)	value ^= (1 << (bit_index))
# define BIT_IS_SET(value, bit_index)	((value) & (1 << (bit_index)))

#endif		/* TOOLS_H_ */
