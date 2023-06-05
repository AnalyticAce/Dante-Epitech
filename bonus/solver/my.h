/*
** EPITECH PROJECT, 2023
** myh
** File description:
** myh
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

#ifndef MY_H
    #define MY_H

typedef struct rocomap{
    int rows;
    int cols;
    char **map;
}rocomap;

char *charge_map(int ac, char **av);
int height(char const *str);
int width(char const *str);
char **malloqueur(char *str);
int is_valid_index(int x, int y, rocomap *link);
void displayer(char **map, int len, int wi);
int main_solver(int x, int y, rocomap *link);
char *file_error(int ac, char **av);
int error(int ac, char **av);
#endif
