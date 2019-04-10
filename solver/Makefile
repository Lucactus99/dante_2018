##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

.RECIPEPREFIX +=

CC		:= gcc

NAME		:= solver
FILES		:= main algorithm create_int_tab error list useful_functions

SRC_NAMES 	:= $(addsuffix .c, $(FILES))
SRC		:= $(addprefix src/, $(SRC_NAMES))

CINC		:= -I include/
CFLAGS		:= -W -Wall -Wextra -pedantic -g

OBJ             := $(SRC:src/%.c=%.o)

RED             := \033[0;31m
CYAN            := \033[0;36m
GOLD            := \033[0;33m
GREEN           := \033[0;32m
WHITE           := \033[0;0m

PREFIX		:= $(CYAN) "[$(NAME)]"

all:        $(NAME)

%.o: src/%.c
        @$(CC) -c $(CFLAGS) $(CINC) -o $@ $^
        @echo "$(PREFIX) $(GREEN)$^ $(GOLD)=> $(GREEN)$@"

$(NAME):        $(OBJ)
        @echo "$(GOLD)Compiling...$(WHITE)\r"
        @gcc $(OBJ) -o $(NAME) $(CINC) $(CFLAGS)
        @echo "$(GOLD)Compiled !$(WHITE)"
        @echo "$(RED)Delete $(GOLD)$(PWD)*.o$(WHITE)"
        @rm -rf $(OBJ)

clean:
        @echo "$(RED)Delete $(GOLD)$(PWD_PATH)*.o$(WHITE)"
        @rm -rf $(OBJ)

fclean:         clean
        @echo "$(RED)Delete $(GOLD)$(PWD)/$(NAME)$(WHITE)"
        @rm -rf $(NAME)

re:             fclean all clean
