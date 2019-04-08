/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** imperfect_algorithm
*/

#include "generator.h"

void imperfect_algorithm(data_t *data)
{
    int direction = 0;

    data->i = 0;
    data->j = 0;
    for (int i = 1; i < data->height; i++) {
        for (int j = 0; j < data->width - 1; j++) {
            data->tab[i][j] = my_rand() % 2;
            data->tab[i][j] += 1;
        }
    }
    while (data->i < data->height - 1 || data->j < data->width - 2) {
        direction = my_rand() % 2;
        if (direction == 0 && data->j < data->width - 2) {
            data->j++;
            data->tab[data->i][data->j] = 2;
        } else if (data->i < data->height - 1) {
            data->i++;
            data->tab[data->i][data->j] = 2;
        }
    }
    display_final_tab(data->tab, data->height, data->width);
    if (data->write_in_file == 1)
        write_in_file(data);
}