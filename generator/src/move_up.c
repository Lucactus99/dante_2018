/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** move_up
*/

#include "generator.h"

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
    if (j - 1 >= 0 && data->tab[i - 1][j - 1] == 2)
        return (NONE);
    if (j + 1 < data->width && data->tab[i - 1][j + 1] == 2)
        return (NONE);
    data->tab[i - 1][j] = 2;
    data->i--;
    return (UP);
}