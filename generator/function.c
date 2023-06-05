/*
** EPITECH PROJECT, 2023
** gen
** File description:
** gen
*/

#include "gen.h"

int reverse_dir(int nb)
{
    const int num_directions = 4;
    const int directions[] = {2, 3, 0, 1};
    if (nb >= 0 && nb < num_directions) {
        return directions[nb];
    } else {
        return -1;
    }
}

int select_direction(labir_t *maze, pos_t *pos, int i)
{
    static int last_dir = -1;
    int num_directions = 4;
    int directions[] = {0, 1, 2, 3};
    if (i >= 5) { return 84;
    } int dir = directions[rand() % num_directions];
    pos_t next_idx = *pos;
    switch (dir) {
    case 0: next_idx.height -= 2; break;
    case 1: next_idx.width += 2; break;
    case 2: next_idx.height += 2; break;
    case 3: next_idx.width -= 2; break;
    } if (next_idx.width < 0 || next_idx.width >=
    maze->width || next_idx.height < 0
        || next_idx.height >= maze->height ||
        maze->tab[next_idx.height][next_idx.width] == '*') {
        return select_direction(maze, pos, i + 1);
    } if (dir == last_dir) {
        return select_direction(maze, pos, i + 1);
    }
    last_dir = reverse_dir(dir); return dir;
}

pos_t *move_idex(labir_t *maze, pos_t *pos, int dir)
{
    int height, width;
    switch (dir) {
    case 0: height = pos->height - 1; width = pos->width;
        break;
    case 1: height = pos->height; width = pos->width + 1;
        break;
    case 2: height = pos->height + 1; width = pos->width;
        break;
    case 3: height = pos->height; width = pos->width - 1;
        break;
    }
    maze->tab[height][width] = '*';
    pos->next = init_list(pos, height + height -
    pos->height, width + width - pos->width);
    return pos->next;
}

int imperfect_labirinthe(labir_t *maze)
{
    srand(time(NULL));
    perfect_labirinthe(maze);
    int num_walls = (maze->width + maze->height) / 2;
    for (int i = 0; i < num_walls; i++) {
        int col = rand() % (maze->width / 2) * 2 + 1;
        int row = rand() % (maze->height / 2) * 2 + 1;
        maze->tab[row][col] = '*';
    }
    return 0;
}

void display_labirinthe(labir_t *extra)
{
    int i = 0;
    while (i < extra->height) {
        my_putstr(extra->tab[i]);
        if (i < extra->height - 1)
            my_putstr("\n");
        i++;
    }
}
