/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** generator
*/

#include <stdlib.h>

char **malloc_map(int x, int y, char **map)
{
    map = malloc(sizeof(char *) * y + 1);

    for (int i = 0; i < y; i++)
        map[i] = malloc(sizeof(char) * x + 1);
    return (map);
}

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;

    if (ac < 3)
        return (84);
    if (ac == 3) {
        x = atoi(av[1]);
        y = atoi(av[2]);
        imperfect_generator(x, y);
    }
    else if (ac == 4 && strcmp(av[3], "perfect") == 0) {
        x = atoi(av[1]);
        y = atoi(av[2]);
        perfect_generator(x, y);
    }
}

int imperfect_generator(int x, int y)
{
    char **map = NULL;
    map = malloc_map(x, y, map);

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            map[i][j] = 'X';
        }
    }
    return (0);
}

int perfect_generator(int x, int y)
{
    char **map = NULL;
    map = malloc_map(x, y, map);

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            map[i][j] = 'X';
        }
    }
    return (0);
}