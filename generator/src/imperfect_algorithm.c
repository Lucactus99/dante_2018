/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** imperfect_algorithm
*/

#include "generator.h"

static int make_loop(data_t *data)
{
    int h = my_rand() % (data->height / 2);

    h++;
    for (int j = 1; j < data->width - 1; j++) {
        if (data->tab[h][j] == 1) {
            if ((data->tab[h][j - 1] == 2 && data->tab[h][j + 1] == 2
            && data->tab[h - 1][j] == 1 && data->tab[h + 1][j] == 1) ||
            (data->tab[h][j - 1] == 1 && data->tab[h][j + 1] == 1
            && data->tab[h - 1][j] == 2 && data->tab[h + 1][j] == 2)) {
                data->tab[h][j] = 2;
                return (1);
            }
        }
    }
    return (make_loop(data));
}

static int make_cluster(data_t *data)
{
    for (int i = 1; i < data->height - 1; i++) {
        if (data->tab[i][data->width - 1] == 2) {
            if (data->tab[i][data->width - 2] == 2
            && (data->tab[i - 1][data->width - 1] == 2
            || data->tab[i + 1][data->width - 1] == 2)) {
                data->tab[i][data->width - 1] = 1;
                return (1);
            }
        }
    }
    return (1);
}

void do_imperfect(data_t *data)
{
    make_cluster(data);
    make_loop(data);
}