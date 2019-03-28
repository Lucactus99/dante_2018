##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

.RECIPEPREFIX +=

CC      =       gcc

SRC     =   src/list.c\
            src/main.c\
            src/error.c\
            src/create_int_tab.c\
            src/useful_functions.c\
            src/algorithm.c

OBJ     =       $(SRC:.c=.o)

NAME    =       solver

CFLAGS  =       -W -Wextra -Wall -ansi -pedantic -g -std=c99 -I ./include

all:    $(NAME)

$(NAME):	$(OBJ)
    $(CC) $(OBJ) -o $(NAME) $(CFLAGS)
    rm -f $(OBJ)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re:		fclean all