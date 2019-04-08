/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "generator.h"

int check_arg_file(int ac, char **av, char **filename)
{
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "txt") == 0) {
            if (i + 1 < ac)
                filename[0] = strdup(av[i + 1]);
            return (1);
        }
    }
    return (0);
}

int check_perfect(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "perfect") == 0) {
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    int **tab;
    data_t *data = malloc(sizeof(data_t));

    if (error_handling_generator(ac, av) == 84)
        return (84);
    data->filename = NULL;
    data->write_in_file = check_arg_file(ac, av, &data->filename);
    data->list = initialisation();
    data->width = atoi(av[1]);
    data->height = atoi(av[2]);
    data->tab = create_int_tab(data->width, data->height);
    if (check_perfect(ac, av) == 1)
        perfect_algorithm(data);
    else
        imperfect_algorithm(data);
    return (0);
}