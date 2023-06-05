/*
** EPITECH PROJECT, 2023
** basic2
** File description:
** basic 2
*/

#include "my.h"

char **malloqueur_b(char *str)
{
    int len = height(str), wi = width(str);
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
