/*
** EPITECH PROJECT, 2023
** error gestion
** File description:
** error gestion
*/

#include "my.h"

char *file_error(int ac, char **av)
{
    struct stat info; stat (av[1], &info); int a = info.st_size;
    char *buffer; buffer = malloc(sizeof(char) * (a + 1));
    int sd = open(av[1], O_RDONLY); int r = read(sd, buffer, a);
    int len = strlen(buffer);
    if (buffer[0] != '*') {
        printf("not '*' at begining.\nit must be '*' at begining and at end\n");
        exit(84);
    }
    for (int s = 0; buffer[s] != '\0'; s++) {
        if (buffer[s] != 'X' && buffer[s] != '\n' && buffer[s] != '*') {
            printf("files does not content good info\n");
            exit(84);
        }
    }
    close(sd);
}
