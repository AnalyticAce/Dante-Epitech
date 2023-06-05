/*
** EPITECH PROJECT, 2023
** solver
** File description:
** solver
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my.h"

int is_valid_index(int x, int y, rocomap *link)
{
    if (x >= 0 && x < link->rows && y >= 0
        && y < link->cols && link->map[x][y] == '*') {
        return 1;
    }
    return 0;
}

int main_solver(int x, int y, rocomap *link)
{
    if (x == link->rows - 1 && y == link->cols - 1) {
        return 1;
    }
    if (is_valid_index(x, y, link)) {
        link->map[x][y] = 'o';
        if (main_solver(x + 1, y, link)) {
            return 1;
        } if (main_solver(x, y + 1, link)) {
            return 1;
        } if (main_solver(x - 1, y, link)) {
            return 1;
        } if (main_solver(x, y - 1, link)) {
            return 1;
        }
        link->map[x][y] = '*';
    } return 0;
}
