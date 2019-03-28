/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** new_solver
*/

#include "solver.h"

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
        printf("\n");
    }
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

int **go_left(int **tab, char *buffer, int *i, int *j)
{
    j[0]--;
    tab[i[0]][j[0]] = 3;
    return (tab);
}

int **go_right(int **tab, char *buffer, int *i, int *j)
{
    j[0]++;
    tab[i[0]][j[0]] = 3;
    return (tab);
}

int **go_down(int **tab, char *buffer, int *i, int *j)
{
    i[0]++;
    tab[i[0]][j[0]] = 3;
    return (tab);
}

int **go_up(int **tab, char *buffer, int *i, int *j)
{
    i[0]--;
    tab[i[0]][j[0]] = 3;
    return (tab);
}

int **go_back_left(int **tab, char *buffer, int *i, int *j)
{
    tab[i[0]][j[0]] = 2;
    j[0]--;
    return (tab);
}

int **go_back_up(int **tab, char *buffer, int *i, int *j)
{
    tab[i[0]][j[0]] = 2;
    i[0]--;
    return (tab);
}

int **go_back_right(int **tab, char *buffer, int *i, int *j)
{
    tab[i[0]][j[0]] = 2;
    j[0]++;
    return (tab);   
}

int **go_back_down(int **tab, char *buffer, int *i, int *j)
{
    tab[i[0]][j[0]] = 2;
    i[0]++;
    return (tab);
}

int is_direction_done(list_t *list, int direction)
{
    if (list->first->done[direction] == 1)
        return (1);
    return (0);
}

int **do_algo(int **tab, char *buffer, list_t *list)
{
    int i = 0;
    int j = 0;
    int direction = 4;

    tab[0][0] = 3;
    while (i < count_lines(buffer) - 1 || j < count_columns(buffer) - 1) {
        if (j + 1 < count_columns(buffer) && tab[i][j + 1] == 2 && is_direction_done(list, RIGHT) == 0) {
            tab = go_right(tab, buffer, &i, &j);
            insertion(list, RIGHT);
        }
        else if (i + 1 < count_lines(buffer) && tab[i + 1][j] == 2 && is_direction_done(list, DOWN) == 0) {
            tab = go_down(tab, buffer, &i, &j);
            insertion(list, DOWN);
        }
        else if (i - 1 >= 0 && tab[i - 1][j] == 2 && is_direction_done(list, UP) == 0) {
            tab = go_up(tab, buffer, &i, &j);
            insertion(list, UP);
        }
        else if (j - 1 >= 0 && tab[i][j - 1] == 2 && is_direction_done(list, LEFT) == 0) {
            tab = go_left(tab, buffer, &i, &j);
            insertion(list, LEFT);
        }
        else {
            direction = list->first->dir;
            deletion(list);
            list->first->done[direction] = 1;
            if (direction == UP)
                tab = go_back_down(tab, buffer, &i, &j);
            if (direction == LEFT)
                tab = go_back_right(tab, buffer, &i, &j);
            if (direction == DOWN)
                tab = go_back_up(tab, buffer, &i, &j);
            if (direction == RIGHT)
                tab = go_back_left(tab, buffer, &i, &j);
        }
    }
    return (tab);
}

int main(int ac, char **av)
{
    int fd;
    int size;
    char *buffer = NULL;
    struct stat sb;
    int **tab;
    list_t *list = malloc(sizeof(list_t));

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
    list = initialisation();
    tab = create_int_tab(buffer);
    tab = do_algo(tab, buffer, list);
    display_final_tab(tab, buffer);
    return (0);
}