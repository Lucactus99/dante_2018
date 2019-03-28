/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver
*/

#ifndef SOLVER_H_
    #define SOLVER_H_

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

enum direction {
    LEFT,
    UP,
    RIGHT,
    DOWN,
    NONE,
};

typedef struct element_s {
    struct element_s *next;
    enum direction dir;
    int done[4];
} element_t;

typedef struct list_s {
    element_t *first;
} list_t;

void display_list(list_t *list);
void deletion(list_t *list);
void insertion(list_t *list, int direction);
list_t *initialisation(void);
int get_last_direction(list_t *list);
void put_done_direction(list_t *list, int direction);

#endif /* !SOLVER_H_ */
