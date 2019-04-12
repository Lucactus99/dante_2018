/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** perfect_algorithm
*/

#include "generator.h"

static void check_end(int **tab, int width, int height)
{
    width--;
    height--;
    if (tab[height - 1][width] == 2 || tab[height][width - 1] == 2)
        return;
    if (tab[height - 1][width] == 1 && (tab[height - 1][width - 1] == 2 && tab[height - 2][width] == 1)) {
        tab[height - 1][width] = 2;
        return;
    }
    if (tab[height - 1][width] == 1 && (tab[height - 1][width - 1] == 1 && tab[height - 2][width] == 2)) {
        tab[height - 1][width] = 2;
        return;
    }
    if (tab[height][width - 1] == 1 && (tab[height - 1][width - 1] == 2 && tab[height][width - 2] == 1)) {
        tab[height][width - 1] = 2;
        return;
    }
    if (tab[height][width - 1] == 1 && (tab[height - 1][width - 1] == 1 && tab[height][width - 2] == 2)) {
        tab[height][width - 1] = 2;
        return;
    }
    if (tab[height - 1][width] == 1 && tab[height - 1][width - 1] == 2 && tab[height - 2][width] == 2) {
        if (tab[height - 1][width - 2] == 1) {
            tab[height - 1][width - 1] = 1;
            tab[height - 1][width] = 2;      
            return;
        } else if (tab[height - 3][width] == 1) {
            tab[height - 2][width] = 1;
            tab[height - 1][width] = 2;
            return;
        }
    }
    if (tab[height][width - 1] == 1 && tab[height - 1][width - 1] == 2 && tab[height][width - 2] == 2) {
        if (tab[height - 2][width - 1] == 1) {
            tab[height - 1][width - 1] = 1;
            tab[height][width - 1] = 2;            
            return;
        } else if (tab[height][width - 3] == 1) {
            tab[height][width - 2] = 1;
            tab[height][width - 1] = 2;
            return;
        }
    }
}
static void is_end(data_t *data)
{
    deletion(data->list);
    if (data->list->first->next == NULL) {
        check_end(data->tab, data->width, data->height);
        if (data->imperfect == 1)
            do_imperfect(data);
        while (checker(data) == 84) {
            data->list = initialisation();
            data->tab = create_int_tab(data->width, data->height);
            perfect_algorithm(data);
        }
        display_final_tab(data->tab, data->width, data->height);
        if (data->write_in_file == 1)
            write_in_file(data);
        exit(0);
    }
    data->i = data->list->first->i;
    data->j = data->list->first->j;
}

static void do_direction(data_t *data)
{
    int direction = NONE;
    int tmp = 0;

    while (direction == NONE) {
        tmp++;
        direction = my_rand() % 4;
        if (direction == LEFT)
            direction = go_left(data);
        if (direction == RIGHT)
            direction = go_right(data);
        if (direction == DOWN)
            direction = go_down(data);
        if (direction == UP)
            direction = go_up(data);
        if (tmp >= 10) {
            is_end(data);
            tmp = 0;
        }
    }
}

void perfect_algorithm(data_t *data)
{
    data->i = 0;
    data->j = 0;
    while (1) {
        do_direction(data);
        insertion(data->list, data->i, data->j);
    }
}