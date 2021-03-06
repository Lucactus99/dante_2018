/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** list
*/

#include "generator.h"

void deletion(list_t *list)
{
    if (list == NULL)
        exit(84);
    if (list->first != NULL) {
        element_t *to_delete = list->first;
        list->first = list->first->next;
        free(to_delete);
    }
}

void insertion_dir(list_t *list, int direction)
{
    element_t *new = malloc(sizeof(element_t));
    if (list == NULL || new == NULL)
        exit(84);
    for (int i = 0; i < 4; i++)
        new->done[i] = 0;
    new->dir = direction;
    new->next = list->first;
    list->first = new;
}

void insertion(list_t *list, int i, int j)
{
    element_t *new = malloc(sizeof(element_t));
    if (list == NULL || new == NULL)
        exit(84);
    for (int i = 0; i < 4; i++)
        new->done[i] = 0;
    new->i = i;
    new->j = j;
    new->next = list->first;
    list->first = new;
}

list_t *initialisation(void)
{
    list_t *list = malloc(sizeof(list_t));
    element_t *element = malloc(sizeof(element_t));

    if (list == NULL || element == NULL)
        exit(84);
    element->dir = NONE;
    for (int i = 0; i < 4; i++)
        element->done[i] = 0;
    element->next = NULL;
    list->first = element;
    return (list);
}