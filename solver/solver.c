/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

static int count_lines(char *buffer)
{
    int counter = 1;

    for (int i = 0; buffer[i + 1] != '\0'; i++) {
        if (buffer[i] == '\n')
            counter++;
    }
    return (counter);
}

static int count_columns(char *buffer)
{
    int counter = 0;

    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++)
        counter++;
    return (counter);
}

int **create_int_tab(char *buffer)
{
    int **tab = malloc(sizeof(int *) * (count_lines(buffer) + 1));
    int a = 0;
    int b = 0;

    for (int i = 0; i < count_lines(buffer); i++)
        tab[i] = malloc(sizeof(int) * (count_columns(buffer) + 1));
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            tab[a][b] = 0;
            b = 0;
            a++;
        } else {
            if (buffer[i] == 'X') {
                tab[a][b] = 1;
            }
            else if (buffer[i] == '*') {
                tab[a][b] = 2;
            }
            b++;
        }
    }
    tab[a][b] = 0;
    return (tab);
}

void display_int_tab(int **tab, char *buffer)
{
    for (int i = 0; i < count_lines(buffer); i++) {
        for (int j = 0; j < count_columns(buffer); j++)
            printf("%d", tab[i][j]);
        printf("\n");
    }
}

int **go_back_algo(int **tab, char *buffer, int *i, int *j)
{
    int a = 0;
    int b = 0;
    int loop = 1;

    while (loop == 1) {
        if (tab[a][b + 1] == 3)
            b++;
        else if (a + 1 < count_lines(buffer) && tab[a + 1][b] == 3)
            a++;
        else if (a - 1 >= 0 && tab[a - 1][b] == 3)
            a--;
        else {
            loop = 0;
            tab[a][b] += 2;
            if (b - 1 >= 0 && tab[a][b - 1] == 3)
                j[0] -= 1;
            else if (a - 1 >= 0 && tab[a - 1][b] == 3)
                i[0] -= 1;
            else
                exit(84);
        }
    }
    return (tab);
}

int **do_algo(int **tab, char *buffer)
{
    int i = 0;

    for (int j = 0; j < count_columns(buffer); j++) {
        if (j + 1 < count_columns(buffer) && tab[i][j + 1] == 5)
            i++;
        if (tab[i][j] == 2) {
            tab[i][j] = 3;
        }
        if (tab[i][j] == 3 && tab[i][j + 1] == 1) {
            if (i + 1 < count_lines(buffer) && tab[i + 1][j] == 2) {
                i++;
                tab[i][j] = 3;
            } else if (i - 1 >= 0 && tab[i - 1][j] == 2) {
                i--;
                tab[i][j] = 3;
            } else {
                do {
                    tab = go_back_algo(tab, buffer, &i, &j);
                } while (tab[i][j] == 1);
                if (tab[i + 1][j + 1] == 1 && tab[i - 1][j + 1] == 1) {
                    j--;
                }
                while (tab[i + 1][j + 1] == 1 && tab[i - 1][j + 1] == 1) {
                    tab = go_back_algo(tab, buffer, &i, &j);
                }
            }
        }
    }
    return (tab);
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
        printf("\n");
    }
}

int main(int ac, char **av)
{
    int fd;
    int size;
    char *buffer = NULL;
    struct stat sb;
    int **tab;

    if (ac != 2)
        return (84);
    stat(av[1], &sb);
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (84);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    if (buffer == NULL)
        return (84);
    size = read(fd, buffer, sb.st_size);
    if (size <= 0) 
        return (84);
    buffer[sb.st_size] = '\0';
    tab = create_int_tab(buffer);
    tab = do_algo(tab, buffer);
    display_final_tab(tab, buffer);
    return (0);
}