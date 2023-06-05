/*
** EPITECH PROJECT, 2023
** main function
** File description:
** main function
*/

#include "my.h"

int main(int ac, char **av)
{
    error(ac, av); file_error(ac, av);
    char *str = charge_map(ac, av);
    rocomap *link = malloc(sizeof(link));
    link->rows = (height(str) + 1); link->cols = width(str);
    link->map = malloqueur(str);
    link->map[link->rows - 1][link->cols - 1] = 'o';
    if (main_solver(0, 0, link)) {
        displayer(link->map, link->rows, link->cols);
    } else {
        printf("no solution found");
    } return 0;
}
