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
#include <string.h>

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
    int imperfect;
    char *filename;
    int write_in_file;
    int width;
    int height;
    int **tab;
    int i;
    int j;
    list_t *list;
} data_t;

// LINKED LIST
void deletion(list_t *);
void insertion(list_t *, int, int);
list_t *initialisation(void);

// USEFUL
void write_in_file(data_t *);
int my_rand(void);
int **create_int_tab(int, int);
void display_help(void);
void display_final_tab(int **, int, int);

// ERROR
int error_handling_generator(int, char **);

// ALGORITHM
void perfect_algorithm(data_t *);
int go_left(data_t *);
int go_right(data_t *);
int go_up(data_t *);
int go_down(data_t *);
void do_imperfect(data_t *);

#endif
