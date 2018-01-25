##
## EPITECH PROJECT, 2018
## LibString
## File description:
## Compile libstring.a
##

include ../../tools.mk

HEADER	=	libstring.h

SRC	=	src/strcmp.c		\
		src/atoi.c		\
		src/strchr.c		\
		src/strcpy.c		\
		src/strdup.c		\
		src/strlen.c		\
		src/put.c

NAME	=	libstring.a

CFLAGS	=	-Werror -pedantic-errors -std=c99 -Ofast

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(call run_command, "Build "$(NAME)": ", ar rc $(NAME) $(OBJ))

%.o:		%.c
		@$(call run_command, "Compiling "$<": ", $(CC) -c $(CFLAGS) $< -o $@)
