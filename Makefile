##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

.RECIPEPREFIX +=

CC      =       gcc

SRC     =   

OBJ     =       $(SRC:.c=.o)

NAME    =       tmp

CFLAGS  =       -W -Wextra -Wall -ansi -pedantic -g -std=c99 -I ./include

all:    $(NAME)

$(NAME):
    @make -sC solver/
    @make -sC generator/

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re:		fclean all