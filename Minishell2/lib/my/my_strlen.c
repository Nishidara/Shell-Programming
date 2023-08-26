/*
** EPITECH PROJECT, 2022
** Jour4
** File description:
** my_strlen
*/

#include <unistd.h>

void my_putchar(char c);

int my_strlen(char *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a++;
    }
    return a;
}
