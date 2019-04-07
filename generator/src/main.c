/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "generator.h"

int main(int ac, char **av)
{
    int **tab;
    data_t *data = malloc(sizeof(data_t));

    if (error_handling_generator(ac, av) == 84)
        return (84);
    data->list = initialisation();
    data->width = atoi(av[1]);
    data->height = atoi(av[2]);
    data->tab = create_int_tab(data->width, data->height);
    perfect_algorithm(data);
    return (0);
}