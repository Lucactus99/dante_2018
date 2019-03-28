/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** algorithm
*/

#include "solver.h"

int **do_algo(int **tab, char *buffer, list_t *list)
{
    int i = 0;
    int j = 0;
    int direction = 4;

    tab[0][0] = 3;
    while (i < count_lines(buffer) - 1 || j < count_columns(buffer) - 1) {
        if (j + 1 < count_columns(buffer) && tab[i][j + 1] == 2 && is_direction_done(list, RIGHT) == 0) {
            j++;
            tab[i][j] = 3;
            insertion(list, RIGHT);
        }
        else if (i + 1 < count_lines(buffer) && tab[i + 1][j] == 2 && is_direction_done(list, DOWN) == 0) {
            i++;
            tab[i][j] = 3;
            insertion(list, DOWN);
        }
        else if (i - 1 >= 0 && tab[i - 1][j] == 2 && is_direction_done(list, UP) == 0) {
            i--;
            tab[i][j] = 3;
            insertion(list, UP);
        }
        else if (j - 1 >= 0 && tab[i][j - 1] == 2 && is_direction_done(list, LEFT) == 0) {
            j--;
            tab[i][j] = 3;
            insertion(list, LEFT);
        }
        else {
            direction = list->first->dir;
            deletion(list);
            list->first->done[direction] = 1;
            if (direction == UP) {
                tab[i][j] = 2;
                i++;
            }
            if (direction == LEFT) {
                tab[i][j] = 2;
                j++;
            }
            if (direction == DOWN) {
                tab[i][j] = 2;
                i--;
            }
            if (direction == RIGHT) {
                tab[i][j] = 2;
                j--;
            }
        }
    }
    return (tab);
}