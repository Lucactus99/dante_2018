/*
** EPITECH PROJECT, 2019
** generator.h
** File description:
** dante generator.h
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
    int i;
    int j;
} element_t;

typedef struct list_s {
    element_t *first;
} list_t;

typedef struct data_s {
    int width;
    int height;
    int **tab;
    int i;
    int j;
    list_t *list;
} data_t;

// LINKED LIST
void display_list(list_t *);
void deletion(list_t *);
void insertion(list_t *, int, int);
list_t *initialisation(void);
int is_direction_done(list_t *, int);

int my_rand(void);
int error_handling_generator(int ac, char **av);
void perfect_algorithm(data_t *data);
int **create_int_tab(int width, int height);
int count_lines(char *buffer);
int count_columns(char *buffer);
void display_int_tab(int **tab, int, int);
void display_final_tab(int **tab, int, int);

#endif
