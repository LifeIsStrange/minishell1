##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Lib's Makefile
##

include ../tools.mk

DIR	=	libstring

all:		$(DIR)

$(DIR):
		@make -C $(@)
		@$(call run_command, "Copying "$@": ", mv $(@)/$(@).a ../build/$(@).a)
		@$(call run_command, "Copying header files of "$@": ", cp $(@)/header/* ../include/lib)

.PHONY: all $(DIR)
