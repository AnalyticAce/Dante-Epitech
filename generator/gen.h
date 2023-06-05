/*
** EPITECH PROJECT, 2023
** myh
** File description:
** myh
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef MY_H
    #define MY_H

typedef struct labir_s {
    int width;
    int height;
    char **tab;
    bool perfector;
    bool newer;
} labir_t;

typedef struct Position_s {
    int width;
    int height;
    struct Position_s *previous;
    struct Position_s *next;
} pos_t;

int reverse_dir(int nb);
int select_direction(labir_t *maze, pos_t *pos, int i);
pos_t *move_idex(labir_t *maze, pos_t *pos, int dir);
int imperfect_labirinthe(labir_t *maze);
void display_labirinthe(labir_t *extra);
labir_t *check_args(int ac, const char **av);
labir_t *malloc_labirinthe(int height, int width, bool p, bool v);
void set_edge(labir_t *maze);
int perfect_labirinthe(labir_t *maze);
pos_t *init_list(pos_t *previous,
const int height, const int width);
void displayer_maze(labir_t *maze);
void my_putchar(char c);
int my_getnbr(const char *str);
int my_putstr(char *str);
int my_strcmp(char const *s1, char const *s2);
#endif
