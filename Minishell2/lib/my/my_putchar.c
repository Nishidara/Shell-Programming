/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-bsmyls-elias.abassi
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
