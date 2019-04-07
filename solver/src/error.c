/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** error
*/

#include "solver.h"

static int check_rect(char *buffer)
{
    int length = 0;
    int counter = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        length++;
    for (int i = 0; buffer[i] != '\0'; i++) {
        counter++;
        if (buffer[i + 1] == '\0') {
            if (buffer[i] == '\n')
                return (84);
        }
        if (buffer[i] == '\n') {
            if (counter != length + 1)
                return (84);
            else
                counter = 0;
        }
    }
    return (0);
}

static int check_char(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != 'X' && buffer[i] != '*' && buffer[i] != '\n')
            return (84);
    }
    return (0);
}

static void check_solution(char *buffer)
{
    int i = 0;

    if (buffer[0] == 'X') {
        printf("No solution found\n");
        exit(0);
    }
    for (; buffer[i + 1] != '\0'; i++);
    if (buffer[i] == 'X') {
        printf("No solution found\n");
        exit(0);
    }
}

int error_handling_solver(char *buffer)
{
    if (check_rect(buffer) == 84)
        return (84);
    if (check_char(buffer) == 84)
        return (84);
    check_solution(buffer);
    return (0);
}