/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-elias.abassi
** File description:
** env
*/

#include "include/my.h"

void print_env(init_t *init)
{
    for (int i = 0; init->cpy_env[i] != NULL; i++) {
        my_putstr(init->cpy_env[i]);
        my_putchar('\n');
    }
}
