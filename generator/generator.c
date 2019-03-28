/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** generator
*/

#include "generator.h"
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

void algo_imperfect(int rows, int cols, generator_t *info)
{
    info->map[0][0] = 2;
    int direction = 0;

    for (int i = 0; i < 4; i++) {
        direction = generate_direction();
        printf("%d\n", direction);
        switch (direction) {
            case 1:
                if (rows - 2 <= 0)
                    continue;
                if (info->map[rows - 2][cols] != 2) {
                    info->map[rows - 2][cols] = 2;
                    info->map[rows - 1][cols] = 2;
                    algo_imperfect(rows - 2, cols, info);  
                }
                break;
            case 2:
                if (cols + 2 >= info->x - 1)
                    continue;
                if (info->map[rows][cols + 2] != 2) {
                    info->map[rows][cols + 2] = 2;
                    info->map[rows][cols + 1] = 2;
                    algo_imperfect(rows, cols + 2, info);
                 }
                 break;
            case 3:
                if (rows + 2 >= info->y - 1)
                    continue;
                if (info->map[rows + 2][cols] != 2) {
                    info->map[rows + 2][cols] = 2;
                    info->map[rows + 1][cols] = 2;
                    algo_imperfect(rows + 2, cols, info);
                }
                break;
            case 4:
                if (cols - 2 <= 0)
                    continue;
                if (info->map[rows][cols - 2] != 2) {
                    info->map[rows][cols - 2] = 2;
                    info->map[rows][cols - 1] = 2;
                    algo_imperfect(rows, cols - 2, info);
                }
                break;
        }
    }
}

int generate_direction(void)
{
    int nb = 0;
    srand(clock());
    nb = rand() % (5 - 1) + 1;
    return (nb);
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
    generator_t *info = malloc(sizeof(generator_t));
    info->x = 0;
    info->y = 0;
    info->rows = 0;
    info->cols = 0;

    if (ac < 3)
        return (84);
    if (ac == 3) {
        info->x = atoi(av[1]);
        info->y = atoi(av[2]);
        imperfect_generator(info);
    }
    else if (ac == 4 && strcmp(av[3], "perfect") == 0) {
        info->x = atoi(av[1]);
        info->y = atoi(av[2]);
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

int imperfect_generator(generator_t *info)
{

    info->map = NULL;
    char **tab = NULL;
    FILE *fp = fopen("maze.txt", "wb+");
    info->map = malloc_map(info->x, info->y, info->map);
    algo_imperfect(0, 0, info);
    tab = transform_int_tab(info->map, info->x, info->y);
    for (int i = 0; i < info->y; i++)
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