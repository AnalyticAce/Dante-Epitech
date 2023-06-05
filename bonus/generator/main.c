/*
** EPITECH PROJECT, 2023
** generator
** File description:
** generator
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "inter.h"

int main(int ac, char **av)
{
    if (ac != 3 && ac != 4) return 84;
    if (ac == 3) complete_inperfect(ac, av); int troi = atoi(av[2]);
    int mdt = troi % 2;
    if (ac == 4 && strcmp("perfect", av[3]) == 0 && mdt == 0)
        complete_perfect_pair(ac, av);
    if (ac == 4 && strcmp("perfect", av[3]) == 0 && mdt != 0)
        complete_perfect_inpair(ac, av);
    if (ac == 4 && strcmp("perfect", av[3]) != 0) exit(84);
    return 0;
}
