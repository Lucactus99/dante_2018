/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** algorithm
*/

#include "generator.h"

int go_left(data_t *data)
{
    int i = data->i;
    int j = data->j;

    if (j - 1 < 0)
        return (NONE);
    if (i - 1 < 0 && i + 1 >= data->height)
        return (NONE);
    if (j - 2 >= 0) {
        if (data->tab[i][j - 1] == 2 || data->tab[i][j - 2] == 2)
            return (NONE);
    }
    if (i - 1 >= 0) {
        if (data->tab[i - 1][j - 1] == 2)
            return (NONE);
    }
    if (i + 1 < data->height) {
        if (data->tab[i + 1][j - 1] == 2)
            return (NONE);
    }
    data->tab[i][j - 1] = 2;
    data->j--;
    return (LEFT);
}

int go_right(data_t *data)
{
    int i = data->i;
    int j = data->j;

    if (j + 1 >= data->width)
        return (NONE);
    if (i - 1 < 0 && i + 1 >= data->height)
        return (NONE);
    if (j + 2 < data->width) {
        if (data->tab[i][j + 1] == 2 || data->tab[i][j + 2] == 2)
            return (NONE);
    }
    if (i - 1 >= 0) {
        if (data->tab[i - 1][j + 1] == 2)
            return (NONE);
    }
    if (i + 1 < data->height) {
        if (data->tab[i + 1][j + 1] == 2)
            return (NONE);
    }
    data->tab[i][j + 1] = 2;
    data->j++;
    return (RIGHT);
}

int go_up(data_t *data)
{
    int i = data->i;
    int j = data->j;

    if (i - 1 < 0)
        return (NONE);
    if (j - 1 < 0 && j + 1 > data->width)
        return (NONE);
    if (i - 2 >= 0) {
        if (data->tab[i - 1][j] == 2 || data->tab[i - 2][j] == 2)
            return (NONE);
    }
    if (j - 1 >= 0) {
        if (data->tab[i - 1][j - 1] == 2)
            return (NONE);
    }
    if (j + 1 <= data->width) {
        if (data->tab[i - 1][j + 1] == 2)
            return (NONE);
    }
    data->tab[i - 1][j] = 2;
    data->i--;
    return (UP);
}

int go_down(data_t *data)
{
    int i = data->i;
    int j = data->j;

    if (i + 1 >= data->height)
        return (NONE);
    if (j - 1 < 0 && j + 1 > data->width)
        return (NONE);
    if (i + 2 < data->height) {
        if (data->tab[i + 1][j] == 2 || data->tab[i + 2][j] == 2)
            return (NONE);
    }
    if (j - 1 >= 0) {
        if (data->tab[i + 1][j - 1] == 2)
            return (NONE);
    }
    if (j + 1 <= data->width) {
        if (data->tab[i + 1][j + 1] == 2)
            return (NONE);
    }
    data->tab[i + 1][j] = 2;
    data->i++;
    return (DOWN);
}

void check_end(int **tab, int width, int height)
{
    width--;
    height--;
    if (tab[height][width - 1] == 1 && tab[height - 1][width] == 1) {
        if (tab[height - 1][width - 1] == 2)
            tab[height - 1][width - 1] = 1;
        if (tab[height][width - 2] == 2)
            tab[height][width - 1] = 2;
        else if (tab[height - 2][width] == 2)
            tab[height - 1][width] = 2;
    }
}

void perfect_algorithm(data_t *data)
{
    int tmp = 0;
    int direction = NONE;

    data->i = 0;
    data->j = 0;
    while (1) {
        direction = NONE;
        tmp = 0;
        while (direction == NONE) {
            tmp++;
            direction = my_rand() % 4;
            if (direction == LEFT) {
                direction = go_left(data);
            }
            if (direction == RIGHT) {
                direction = go_right(data);
            }
            if (direction == DOWN) {
                direction = go_down(data);
            }
            if (direction == UP) {
                direction = go_up(data);
            }
            if (tmp >= 10) {
                deletion(data->list);
                if (data->list->first->next == NULL) {
                    check_end(data->tab, data->width, data->height);
                    display_final_tab(data->tab, data->width, data->height);
                    exit(0);
                }
                data->i = data->list->first->i;
                data->j = data->list->first->j;
                tmp = 0;
            }
        }
        insertion(data->list, data->i, data->j);
    }
}