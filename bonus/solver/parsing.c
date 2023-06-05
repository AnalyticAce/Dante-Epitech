/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** parsing
*/

#include "my.h"

char *charge_map(int ac, char **av)
{
    struct stat info;
    stat (av[1], &info);
    int a = info.st_size;
    char *buffer; buffer = malloc(sizeof(char) * (a + 1));
    int sd = open(av[1], O_RDONLY);
    int r = read(sd, buffer, a);
    close(sd);
    return (buffer);
}
