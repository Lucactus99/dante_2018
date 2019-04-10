/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver
*/

#include "generator.h"

static void move_pos(data_t *data, int pos, int direction)
{
    if (pos == 0) {
        if (direction == DOWN)
            data->i++;
        else
            data->i--;
    } else {
        if (direction == RIGHT)
            data->j++;
        else
            data->j--;
    }
    data->tab[data->i][data->j] = 3;
    insertion_dir(data->list, direction);
}

static int check_no_solution(list_t *list)
{
    if (list->first == NULL)
        return (1);
    if (list->first->next == NULL) {
        if (list->first->done[RIGHT] == 1 && list->first->done[DOWN] == 1)
            return (1);
    }
    return (0);
}

static int go_back(data_t *data)
{
    int direction = data->list->first->dir;

    deletion(data->list);
    if (check_no_solution(data->list) == 1)
        return (84);
    data->list->first->done[direction] = 1;
    if (direction != NONE)
        data->tab[data->i][data->j] = 2;
    if (direction == UP)
        data->i++;
    if (direction == LEFT)
        data->j++;
    if (direction == DOWN)
        data->i--;
    if (direction == RIGHT)
        data->j--;
    return (0);
}

static int do_algo(data_t *data)
{
    if (data->j + 1 < data->width &&
    data->tab[data->i][data->j + 1] == 2 &&
    is_direction_done(data->list, RIGHT) == 0) {
        move_pos(data, 1, RIGHT);
    } else if (data->i + 1 < data->height &&
    data->tab[data->i + 1][data->j] == 2 &&
    is_direction_done(data->list, DOWN) == 0) {
        move_pos(data, 0, DOWN);
    } else if (data->i - 1 >= 0 && data->tab[data->i - 1][data->j] == 2 &&
    is_direction_done(data->list, UP) == 0) {
        move_pos(data, 0, UP);
    } else if (data->j - 1 >= 0 && data->tab[data->i][data->j - 1] == 2 &&
    is_direction_done(data->list, LEFT) == 0) {
        move_pos(data, 1, LEFT);
    } else {
        if (go_back(data) == 84)
            return (84);
    }
    return (0);
}

int algorithm(data_t *data)
{
    data->i = 0;
    data->j = 0;
    data->tab[0][0] = 3;
    while (data->i < data->height - 1 || data->j < data->width - 1) {
        if (do_algo(data) == 84) {
            return (84);
        }
    }
    return (0);
}