/*
** EPITECH PROJECT, 2023
** gen
** File description:
** gen
*/

#include "gen.h"

pos_t *init_list(pos_t *previous,
int height, int width)
{
    pos_t *ret = malloc(sizeof(pos_t));
    ret->previous = previous;
    ret->height = height;
    ret->width = width;
    ret->next = NULL;
    if (previous == NULL) {
        return ret;
    }
    pos_t *current = previous;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = ret;
    return ret;
}

int main(const int ac, const char **av)
{
    labir_t *maze = check_args(ac, av);
    if (maze == NULL)
        return 84;
    bool perfector = maze->perfector;
    if (perfector)
        perfect_labirinthe(maze);
    else
        imperfect_labirinthe(maze);
    int i = 0;
    while (i < maze->height) {
        write(1, maze->tab[i], maze->width);
        if (i < maze->height - 1)
            write(1, "\n", 1);
        i++;
    }
    free(maze);
    return 0;
}
