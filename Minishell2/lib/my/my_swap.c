/*
** EPITECH PROJECT, 2022
** Jour4
** File description:
** my_swap
*/


#include <stdio.h>
#include <unistd.h>

void my_putchar(char c);

int my_swap(int *a, int *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}
