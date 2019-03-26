/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** generator
*/

#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int get_rand_int(void)
{
    int tmp = rand_lim(1, 100000000000);

    if (tmp % 7 == 0)
        return (1);
    else if (tmp % 8 == 0)
        return (2);
    return (get_rand_int());
}

int get_number_map(int i, int j, int **map)
{
    if (map[i - 1][j] == 2 && map[i - 1][j + 1] == 2 && map[i - 1][j - 1] == 2)
        return (1);
    if (map[i - 1][j] == 2 && map[i - 1][j + 1] == 1 && map[i - 1][j - 1] == 2)
        return (2);
    if (map[i - 1][j] == 1 && map[i - 1][j + 1] == 2 && map[i - 1][j - 1] == 2)
        return (1);
    if (map[i - 1][j] == 1 && map[i - 1][j + 1] == 1 && map[i - 1][j - 1] == 2)
        return (2);
    if (map[i - 1][j] == 2 && map[i - 1][j + 1] == 2 && map[i - 1][j - 1] == 1)
        return (2);
    if (map[i - 1][j] == 2 && map[i - 1][j + 1] == 1 && map[i - 1][j - 1] == 1)
        return (1);
    if (map[i - 1][j] == 1 && map[i - 1][j + 1] == 2 && map[i - 1][j - 1] == 1)
        return (2);
    if (map[i - 1][j] == 1 && map[i - 1][j + 1] == 1 && map[i - 1][j - 1] == 1)
        return (1);
    return (-1);
}

int **algo_imperfect(int x, int y, int **map)
{
    srandom(time(NULL));
    for (int i = 0; i < x; i++) {
        map[0][i] = get_rand_int();
    }
    map[0][0] = 2;
    map[0][1] = 2;
    for (int i = 1; i < y; i++) {
        map[i][0] = 1;
        for (int j = 1; j < x - 1; j++) {
            map[i][j] = get_number_map(i, j, map);
            if (map[i][j] == -1)
                exit(84);
        }
        map[i][x - 1] = 1;
    }
    map[y - 1][x - 2] = 2;
    map[y - 1][x - 1] = 2;
    return (map);
}

int **malloc_map(int x, int y, int **map)
{
    map = malloc(sizeof(int *) * (y + 1));

    for (int i = 0; i < y + 1; i++)
        map[i] = malloc(sizeof(int) * (x + 1));
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            map[i][j] = 1;
        }
        map[i][x] = 0;
    }
    map[y] = NULL;
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
      // perfect_generator(x, y);
    }
}

char **transform_int_tab(int **tab_int, int x, int y)
{
    char **tab = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i < y + 1; i++)
        tab[i] = malloc(sizeof(char) * (x + 1));
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (tab_int[i][j] == 1)
                tab[i][j] = 'X';
            else if (tab_int[i][j] == 2)
                tab[i][j] = '*';
            else
                exit(84);
        }
        tab[i][x] = '\0';
    }
    tab[y] = NULL;
    return (tab);
}

int imperfect_generator(int x, int y)
{

    int **map = NULL;
    char **tab = NULL;
    FILE *fp = fopen("maze.txt", "wb+");
    map = malloc_map(x, y, map);
    map = algo_imperfect(x, y, map);
    tab = transform_int_tab(map, x, y);
    for (int i = 0; i < y; i++)
        fprintf(fp, "%s\n", tab[i]);
    return (0);
}


int rand_lim(int min, int max)
{
    return (((random() % (int)(((max) + 1) - (min))) + (min)));
}

/*int perfect_generator(int x, int y)
{
    int **map = NULL;
    map = malloc_map(x, y, map);
    for (int i = 0; i < y; i++)
        printf("%d\n", map[i]);
    return (0);
}*/