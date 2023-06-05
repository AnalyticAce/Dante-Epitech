/*
** EPITECH PROJECT, 2023
** replacer
** File description:
** replacer
*/

#include "inter.h"

void replacer_perfect_inpair(char **map, int width, int height, inter *link)
{
    for (link->j = 0; link->j < width; link->j++) {
        if (link->i == 0 || link->i == height - 1) {
            map[link->i][link->j] = '*';
        } else {
            map[link->i][link->j] = (link->i % 2 == 1) ? 'X' : '*';
        }
    }
}

void replacer_perfect_pair(char **map, int width, int height, inter3 *link)
{
    map[0][0] = '*';
    for (link->j = 0; link->j < width; link->j++) {
        if (link->i == height - 1) {
            map[link->i][link->j] = '*';
        } if (link->i == height - 2) {
            map[link->i][link->j] = 'X';
        } else {
            map[link->i][link->j] = (link->i % 2 == 1) ? '*' : 'X';
        }
    }
}

void replace_inperfect(char **map, int width, int height, inter2 *la)
{
    for (la->j = 0; la->j < width; la->j++) {
        if (la->i == 0 || la->i == height - 1 ||
            la->j == 0 || la->j == width - 1) {
            map[la->i][la->j] = '*';
        } if (!(la->i == 0 || la->i == height - 1 ||
            la->j == 0 || la->j == width - 1) && la->i % 2 == 1) {
            map[la->i][la->j] = 'X';
        } else {
            map[la->i][la->j] = '*';
        }
    }
}

void replace_random(char **map, int width, int height)
{
    srand(time(NULL)); int i = 0; int j = 0;
    for (i = 1; i < height - 1; i++) {
        j = rand() % (width - 2) + 1;
        map[i][j] = '*';
    }
}
