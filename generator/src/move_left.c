/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** move_left
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
    if (i - 1 >= 0 && data->tab[i - 1][j - 1] == 2)
        return (NONE);
    if (i + 1 < data->height && data->tab[i + 1][j - 1] == 2)
        return (NONE);
    data->tab[i][j - 1] = 2;
    data->j--;
    return (LEFT);
}