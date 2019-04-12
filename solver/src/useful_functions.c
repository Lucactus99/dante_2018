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

void display_final_tab(char **tab, char *buffer)
{
    for (int i = 0; i < count_lines(buffer); i++) {
        printf("%s", tab[i]);
        if (i < count_lines(buffer) - 1)
            printf("\n");
    }
}