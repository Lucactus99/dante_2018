/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** create_int_tab
*/

#include "solver.h"

int **create_int_tab(char *buffer)
{
    int **tab = malloc(sizeof(int *) * (count_lines(buffer) + 1));
    int a = 0;
    int b = 0;

    for (int i = 0; i < count_lines(buffer); i++)
        tab[i] = malloc(sizeof(int) * (count_columns(buffer) + 1));
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'X') {
            tab[a][b] = 1;
            b++;
        } else if (buffer[i] == '*') {
            tab[a][b] = 2;
            b++;
        } else {
            tab[a][b] = 0;
            b = 0;
            a++;
        }
    }
    return (tab);
}