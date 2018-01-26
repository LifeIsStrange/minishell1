##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

include tools.mk

DEBUG	=	yes

LIB	=	-lstring

SRC	=	src/main.c			\
		src/get_next_line.c		\
		src/builtin/cd.c		\
		src/builtin/env.c		\
		src/command.c			\
		src/launch.c			\
		src/utils.c			\
		src/env/add.c			\
		src/env/init.c			\
		src/env/remove.c		\
		src/env/utils.c			\
		src/path_to_array.c		\
		src/str_to_array.c

NAME	=	mysh

CC	=	gcc

CFLAGS	=	-Iinclude/ -Iinclude/lib -std=c99

LDFLAGS	=	-Lbuild ${LIB}

ifeq ($(DEBUG), yes)
		CFLAGS	+= -W -Wall -Wextra -pedantic -ggdb3
else
		CFLAGS	+= -Werror -pedantic-errors
endif

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	lib $(OBJ)
ifeq ($(DEBUG), yes)
		@tput setaf 1; tput bold
		@$(call draw_debug_mode)
		@tput sgr0
endif
		@$(call run_command, "Compiling "$(NAME)": ", $(CC) -o $(NAME) $(OBJ) $(LDFLAGS))

%.o:		%.c
		@$(call run_command, "Compiling "$<": ", $(CC) -c $(CFLAGS) $< -o $@)

lib:
		@make -C lib

clean:
		@$(call run_command, "Deleting Coverage files: ", find . -name "*.gcda" -name "*gcno" -delete)
		@$(call run_command, "Deleting OBJ files: ", find . -name "*.o" -delete)
		@$(call run_command, "Deleting Temp files: ", find . -name "*~" -name "#*" -name "*#" -delete)
		@$(call run_command, "Deleting Valgrind files: ", find . -name "vgcore.*" -delete)

fclean:		clean
		@$(call run_command, "Deleting "$(NAME)": ", rm -rf $(NAME))
		@$(call run_command, "Deleting Lib: ", rm -rf lib/output/*)
		@$(call run_command, "Deleting Lib's header files: ", rm -rf include/lib/*)

re:		fclean all

.PHONY:		lib clean fclean re
