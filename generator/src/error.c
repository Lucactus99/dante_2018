/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** error
*/

#include "generator.h"

static int check_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (84);
    }
    return (0);
}

int error_handling_generator(int ac, char **av)
{
    if (ac == 2) {
        if (strcmp(av[1], "-h") == 0) {
            display_help();
            exit(0);
        }
    }
    if (ac < 3 || ac > 6) {
        display_help();
        return (84);
    }
    if (check_num(av[1]) == 84 || check_num(av[2]) == 84) {
        display_help();
        return (84);
    }
    return (0);
}