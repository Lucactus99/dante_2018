/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** generator
*/

#include <stdlib.h>


int **algo_imperfect(int x, int y, int **map, int posx, int posy)
{
    int **visited = malloc(sizeof(int *) * y + 1);
    for (int i = 0; i < y + 1; i++)
        visited[i] = malloc(sizeof(int) * x + 1);
    visited[posx][posy] = 1;
    map[posx][posy] = 0;
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
        map[i][x] = '\0';
    }
    map[0][0] = 0;
    map[x - 1][y - 1] = 0;
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

int imperfect_generator(int x, int y)
{
    int **map = NULL;
    map = malloc_map(x, y, map);
 //   map = algo_imperfect(x, y, map);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%d", map[i][j]);
        }
        putchar('\n');
    }
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