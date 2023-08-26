/*
** EPITECH PROJECT, 2022
** Jour4
** File description:
** my_putsr
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar_fd(char c, int fd);

void my_putstr_fd(char *str, int fd)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar_fd(str[a], fd);
        a++;
    }
}
