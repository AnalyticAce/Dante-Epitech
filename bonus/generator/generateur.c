/*
** EPITECH PROJECT, 2023
** generator
** File description:
** generator
*/

#include "inter.h"

char **generate_perfect_inpair(int width, int height)
{
    inter *link = malloc(sizeof(link));
    link->i = 0; link->j = 0;
    char** map = (char**) malloc(height * sizeof(char*));
    for (link->i = 0; link->i < height; link->i++) {
        map[link->i] = (char*) malloc(width * sizeof(char));
        replacer_perfect_inpair(map, width, height, link);
    }
    return map;
}

char **generate_perfect_pair(int width, int height)
{
    inter3 *link = malloc(sizeof(link));
    link->i = 0; link->j = 0;
    char** map = (char**) malloc(height * sizeof(char*));
    for (link->i = 0; link->i < height; link->i++) {
        map[link->i] = (char*) malloc(width * sizeof(char));
        replacer_perfect_pair(map, width, height, link);
    }
    return map;
}

char  **generate_inperfect(int width, int height)
{
    inter2 *la = malloc(sizeof(la));
    la->i = 0; la->j = 0;
    char** map = (char**)malloc(height * sizeof(char*));
    for (la->i = 0; la->i < height; la->i++) {
        map[la->i] = (char*)malloc(width * sizeof(char));
        replace_inperfect(map, width, height, la);
    }
    return map;
}
