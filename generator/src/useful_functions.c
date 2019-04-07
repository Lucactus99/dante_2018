/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** useful_functions
*/

#include "generator.h"

int my_rand(void)
{
    static int first = 0;

    if (first == 0) {
        srand(time(NULL));
        first += 1;
    }
    return (rand());
}

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

void display_int_tab(int **tab, int width, int height)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            printf("%d", tab[i][j]);
        printf("\n");
    }
}

void display_final_tab(int **tab, int width, int height)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[i][j] == 1)
                printf("X");
            else if (tab[i][j] == 2)
                printf("*");
        }
        if (i < height - 1)
            printf("\n");
    }
}