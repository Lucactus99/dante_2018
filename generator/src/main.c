/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "generator.h"

static int check_arg_file(int ac, char **av, char **filename)
{
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "txt") == 0) {
            if (i + 1 < ac)
                filename[0] = strdup(av[i + 1]);
            return (1);
        }
    }
    return (0);
}

static int check_perfect(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "perfect") == 0) {
            return (1);
        }
    }
    return (0);
}

void display_help(void)
{
    int fd = open("./src/help", O_RDONLY);
    char buffer[182];

    if (fd < 0) {
        perror("fd");
        exit(84);
    }
    if (read(fd, buffer, 182) <= 0) {
        perror("read");
        exit(84);
    }
    buffer[181] = '\0';
    printf("%s\n", buffer);
    close(fd);
}

int main(int ac, char **av)
{
    data_t *data = malloc(sizeof(data_t));

    if (error_handling_generator(ac, av) == 84)
        return (84);
    data->filename = NULL;
    data->write_in_file = check_arg_file(ac, av, &data->filename);
    data->list = initialisation();
    data->width = atoi(av[1]);
    data->height = atoi(av[2]);
    data->tab = create_int_tab(data->width, data->height);
    if (check_perfect(ac, av) == 1)
        data->imperfect = 0;
    else
        data->imperfect = 1;
    perfect_algorithm(data);
    return (0);
}