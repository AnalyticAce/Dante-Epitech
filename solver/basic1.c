/*
** EPITECH PROJECT, 2023
** basic function1
** File description:
** basic function 1
*/

#include "my.h"

int error(int ac, char **av)
{
    struct stat stater;
    if (stat(av[1], &stater) == -1) {
        printf("file does not exist\n");
        exit (84);
    }
    if (ac == 1) {
        printf("miss arg\n");
        exit (84);
    }
    if (ac > 2) {
        printf("too many argument\n");
        exit (84);
    }
}

int height(char const *str)
{
    int i = 0; int j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            j++;
    }
    return (j);
}

int width(char const *str)
{
    int i = 0; int k = 0;
    while (str[i] != '\n') {
        i++;
    }
    return (i);
}

char **malloqueur(char *str)
{
    int len = (height(str) + 1), wi = width(str);
    int i = 0, x = 0;
    char **alou = malloc(sizeof(char*) * (len + 2));
    for (i = 0; i < len; i++) {
        alou[i] = malloc(sizeof(char) * (wi + 2));
    }
    int k = 0, j = 0;
    for (k = 0; k < len; k++) {
        for (j = 0; j < wi + 1 && str[x]; j++) {
            alou[k][j] = str[x];
            x++;
        }
        alou[k][j] = '\0';
    }
    alou[k] = NULL;
    return alou;
}

void displayer(char **map, int len, int wi)
{
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < wi; j++) {
            printf("%c",map[i][j]);
        }
        (i < len - 1) ? printf("\n") : 0;
    }
}
