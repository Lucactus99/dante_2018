/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "solver.h"

static char *open_file(int ac, char **av)
{
    int fd;
    int size;
    char *buffer = NULL;
    struct stat sb;

    if (ac != 2)
        exit(84);
    stat(av[1], &sb);
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        exit(84);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    if (buffer == NULL)
        exit(84);
    size = read(fd, buffer, sb.st_size);
    if (size <= 0) 
        exit(84);
    buffer[sb.st_size] = '\0';
    return (buffer);
}

int main(int ac, char **av)
{
    int **tab;
    list_t *list = malloc(sizeof(list_t));
    char *buffer = open_file(ac, av);

    if (error_handling_maze(buffer) == 84)
        return (84);
    list = initialisation();
    tab = create_int_tab(buffer);
    tab = do_algo(tab, buffer, list);
    display_final_tab(tab, buffer);
    return (0);
}