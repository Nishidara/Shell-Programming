/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
