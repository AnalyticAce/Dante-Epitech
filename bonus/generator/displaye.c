/*
** EPITECH PROJECT, 2023
** display map
** File description:
** display map
*/

#include "inter.h"

void complete_inperfect(int ac, char **av)
{
    int width = atoi(av[1]); int height = atoi(av[2]);
    if (width <= 0 || height <= 0) exit(84); (width == 2) ? exit(0) : 0;
    char **map = generate_inperfect(width, height);
    replace_random(map, width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        (i < height - 1) ? printf("\n") : 0;
    }
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
}

void complete_perfect_inpair(int ac, char **av)
{
    int width = atoi(av[1]); int height = atoi(av[2]);
    if (width <= 0 || height <= 0) exit(84); (width == 2) ? exit(0) : 0;
    char **map = generate_perfect_inpair(width, height);
    replace_random(map, width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        (i < height - 1) ? printf("\n") : 0;
    }
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
}

void complete_perfect_pair(int ac, char **av)
{
    int width = atoi(av[1]); int height = atoi(av[2]);
    if (width <= 0 || height <= 0) exit(84); (width == 2) ? exit(0) : 0;
    char **map = generate_perfect_pair(width, height);
    replace_random(map, width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        (i < height - 1) ? printf("\n") : 0;
    }
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
}
