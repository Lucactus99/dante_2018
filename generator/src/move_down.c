/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** move_down
*/
#include "generator.h"

int go_down(data_t *data)
{
    int i = data->i;
    int j = data->j;

    if (i + 1 >= data->height)
        return (NONE);
    if (i + 1 == data->height - 1 && j == data->width - 1) {
        data->tab[i + 1][j] = 2;
        data->i++;
        return (DOWN);
    }
    if (j - 1 < 0 && j + 1 > data->width)
        return (NONE);
    if (i + 2 < data->height) {
        if (data->tab[i + 1][j] == 2 || data->tab[i + 2][j] == 2)
            return (NONE);
    }
    if (j - 1 >= 0 && data->tab[i + 1][j - 1] == 2)
        return (NONE);
    if (j + 1 < data->width && data->tab[i + 1][j + 1] == 2)
        return (NONE);
    data->tab[i + 1][j] = 2;
    data->i++;
    return (DOWN);
}