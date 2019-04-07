/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** useful_functions
*/

#include "solver.h"

int count_lines(char *buffer)
{
    int counter = 1;

    for (int i = 0; buffer[i + 1] != '\0'; i++) {
        if (buffer[i] == '\n')
            counter++;
    }
    return (counter);
}

int count_columns(char *buffer)
{
    int counter = 0;

    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++)
        counter++;
    return (counter);
}

void display_int_tab(int **tab, char *buffer)
{
    for (int i = 0; i < count_lines(buffer); i++) {
        for (int j = 0; j < count_columns(buffer); j++)
            printf("%d", tab[i][j]);
        printf("\n");
    }
}

void display_final_tab(int **tab, char *buffer)
{
    for (int i = 0; i < count_lines(buffer); i++) {
        for (int j = 0; j < count_columns(buffer); j++) {
            if (tab[i][j] == 1)
                printf("X");
            else if (tab[i][j] == 3)
                printf("o");
            else
                printf("*");
        }
        if (i < count_lines(buffer) - 1)
            printf("\n");
    }
}