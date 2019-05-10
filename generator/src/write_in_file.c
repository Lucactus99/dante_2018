/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** write_in_file
*/

#include "generator.h"

void write_in_file(data_t *data)
{
    FILE *fp;

    if (data->filename != NULL)
        fp = fopen(data->filename, "wb+");
    else
        fp = fopen("maze.txt", "wb+");
    if (fp == NULL)
        exit(84);
    for (int i = 0; i < data->height; i++) {
        for (int j = 0; j <= data->width; j++) {
            if (data->tab[i][j] == 1)
                fprintf(fp, "X");
            else
                fprintf(fp, "*");
        }
        if (i < data->height - 1)
            fprintf(fp, "\n");
    }
    fclose(fp);
}