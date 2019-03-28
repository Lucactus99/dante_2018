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

// LINKED LIST
void display_list(list_t *);
void deletion(list_t *);
void insertion(list_t *, int);
list_t *initialisation(void);
int is_direction_done(list_t *, int);

// USEFUL
int count_lines(char *);
int count_columns(char *);

// ERROR
int error_handling_maze(char *);

// ALGORITHM
int **create_int_tab(char *);
void display_final_tab(int **, char *);
int **do_algo(int **, char *, list_t *);

#endif /* !SOLVER_H_ */
