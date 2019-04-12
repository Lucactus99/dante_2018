/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** perfect_algorithm
*/

#include "generator.h"

static int check_end(data_t *data)
{
    if (data->tab[data->height - 1][data->width - 1] == 1)
        return (84);
    if (data->tab[data->height - 2][data->width - 1] == 1
    && data->tab[data->height - 1][data->width - 2] == 1) {
        return (84);
    }
    return (0);
}

static void is_end(data_t *data)
{
    deletion(data->list);
    if (data->list->first->next == NULL) {
        if (data->imperfect == 1)
            do_imperfect(data);
        while (check_end(data) == 84) {
            data->list = initialisation();
            data->width += 1;
            data->tab = create_int_tab(data->width, data->height);
            perfect_algorithm(data);
        }
        data->tab[data->height - 1][data->width] = 2;
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
    data->width -= 1;
    while (1) {
        do_direction(data);
        insertion(data->list, data->i, data->j);
    }
}