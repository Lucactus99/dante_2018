/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "solver.h"

static int get_fd(int ac, char **av)
{
    int fd;

    if (ac != 2)
        exit(84);
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        exit(84);
    return (fd);
}

static char *open_file(int ac, char **av)
{
    int fd = get_fd(ac, av);
    int size;
    char *buffer = NULL;
    struct stat sb;

    stat(av[1], &sb);
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
    data_t *data = malloc(sizeof(data_t));

    if (ac != 2) {
        printf("Usage: ./solver [maze]\n");
        return (0);
    } else
        data->buffer = open_file(ac, av);
    if (error_handling_solver(data->buffer) == 84)
        return (84);
    data->list = initialisation();
    data->tab = transform_2d(data->buffer, '\n');
    algorithm(data);
    return (0);
}