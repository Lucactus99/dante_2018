/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** create_int_tab
*/

#include "generator.h"

int **create_int_tab(int width, int height)
{
    int **tab = malloc(sizeof(int *) * (height));
    int i = 0;
    int j = 0;

    for (int a = 0; a < height; a++)
        tab[a] = malloc(sizeof(int) * (width + 1));
    for (; i < height; i++) {
        j = 0;
        for (; j < width; j++) {
            tab[i][j] = 1;
        }
    }
    tab[0][0] = 2;
    tab[i - 1][j - 1] = 2;
    return (tab);
}