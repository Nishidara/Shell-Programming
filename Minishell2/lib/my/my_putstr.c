/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-bsmyls-elias.abassi
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(char *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
}
