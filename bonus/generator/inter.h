/*
** EPITECH PROJECT, 2023
** int container
** File description:
** int container
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef INTER_H
    #define INTER_H
typedef struct cp{
    int i;
    int j;
}inter;

typedef struct cp2{
    int i;
    int j;
}inter2;

typedef struct cp3{
    int i;
    int j;
}inter3;
void replacer_perfect_inpair(char **map, int width, int height, inter *link);
void replacer_perfect_pair(char **map, int width, int height, inter3 *link);
void replace_inperfect(char **map, int width, int height, inter2 *la);
void replace_random(char **map, int width, int height);
char **generate_perfect_inpair(int width, int height);
char **generate_perfect_pair(int width, int height);
char **generate_inperfect(int width, int height);
void complete_inperfect(int ac, char **av);
void complete_perfect_inpair(int ac, char **av);
void complete_perfect_pair(int ac, char **av);
#endif
