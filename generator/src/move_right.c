/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** move_right
*/

#include "generator.h"

int go_right(data_t *data)
{
    int i = data->i;
    int j = data->j;

    if (j + 1 >= data->width)
        return (NONE);
    if (j + 1 == data->width - 1 && i == data->height - 1) {
        data->tab[i][j + 1] = 2;
        data->j++;
        return (RIGHT);
    }
    if (i - 1 < 0 && i + 1 >= data->height)
        return (NONE);
    if (j + 2 < data->width) {
        if (data->tab[i][j + 1] == 2 || data->tab[i][j + 2] == 2)
            return (NONE);
    }
    if (i - 1 >= 0 && data->tab[i - 1][j + 1] == 2)
        return (NONE);
    if (i + 1 < data->height && data->tab[i + 1][j + 1] == 2)
        return (NONE);
    data->tab[i][j + 1] = 2;
    data->j++;
    return (RIGHT);
}