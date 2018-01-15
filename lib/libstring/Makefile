##
## EPITECH PROJECT, 2018
## LibString
## File description:
## Compile libstring.a
##

include ../../tools.mk

HEADER	=	libstring.h

SRC	=	src/my_strcmp.c		\
		src/my_strncmp.c	\
		src/my_getnbr.c		\
		src/my_strchr.c		\
		src/my_strncpy.c

NAME	=	libstring.a

CFLAGS	=	-Werror -pedantic-errors -std=c99 -Ofast

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(call run_command, "Build "$(NAME)": ", ar rc $(NAME) $(OBJ))

%.o:		%.c
		@$(call run_command, "Compiling "$<": ", $(CC) -c $(CFLAGS) $< -o $@)
