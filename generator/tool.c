/*
** EPITECH PROJECT, 2023
** gen
** File description:
** gen
*/

#include "gen.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_getnbr(const char *str)
{
    int signe = 1, nombre = 0, i = 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            signe = signe * -1;
        i++;
    } while (str[i] >= '0' && str[i] <= '9') {
        nombre = ((nombre * 10) + (str[i] - 48));
        i++;
    }
    return (nombre * signe);
}

int my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        *s1++;
        *s2++;
    }
    return (*s1 - *s2);
}
