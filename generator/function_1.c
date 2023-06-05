/*
** EPITECH PROJECT, 2023
** gen
** File description:
** gen
*/

#include "gen.h"

labir_t *check_args(int ac, const char **av)
{
    bool val ,pin = false;
    int width, height = 0;
    if (ac < 3 || ac > 5) {
        return NULL;
    } width = my_getnbr(av[1]); height = my_getnbr(av[2]);
    if (width < 2 || height < 2) {
        return NULL;
    } int i = 3;
    while (i < ac) {
        if (!my_strcmp(av[i], "perfect")) {
            pin = true;
        }
        i++;
    }
    return malloc_labirinthe(height, width, pin, val);
}

labir_t *malloc_labirinthe(int height, int width, bool pin, bool val)
{
    labir_t *maze = (labir_t *)malloc(sizeof(labir_t));
    if (maze == NULL) {
        return NULL;
    } maze->width = width; maze->height = height;
    maze->perfector = pin; maze->newer = val;
    maze->tab = (char **)malloc(sizeof(char *) * height);
    if (maze->tab == NULL) {
        free(maze); return NULL;
    } for (int i = 0; i < height; i++) {
        maze->tab[i] = (char *)malloc(sizeof(char) * (width + 1));
        memset(maze->tab[i], 'X', width);
        maze->tab[i][width] = '\0';
    } maze->tab[height - 1][width - 1] = 'E'; return maze;
}

void set_edge(labir_t *maze)
{
    int i = maze->width - 1;
    while (i != 0) {
        maze->tab[maze->height - 1][i] = '*';
        if (maze->tab[maze->height - 2][i] == '*')
            break;
        i--;
    }
}

void displayer_maze(labir_t *maze)
{
    if (maze->newer) {
        display_labirinthe(maze);
        my_putstr("\n\n");
    }
}

int perfect_labirinthe(labir_t *maze)
{
    pos_t *pos = init_list(NULL, 0, 0);
    int dir = -1, i;
    for (;;) {
        displayer_maze(maze);
        srand(time(NULL));
        maze->tab[pos->height][pos->width] = '*';
        dir = select_direction(maze, pos, 0);
        for (i = 0; dir == 84 && pos->previous != NULL
        && i < maze->width * maze->height; ++i) {
            pos = pos->previous;
            dir = select_direction(maze, pos, 0);
        } if (dir != 84) {
            pos = move_idex(maze, pos, dir);
        } else {
            break;
        } if (maze->newer) {
            usleep(50000);
        }
    } set_edge(maze); return 0;
}
