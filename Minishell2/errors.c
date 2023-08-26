/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-elias.abassi
** File description:
** errors
*/

#include "include/my.h"

void not_found(init_t *init, char ***tab)
{
    if (my_strncmp (tab[0][0], ";", 1) != 0) {
        my_putstr(tab[init->x][0]);
        my_putstr(": Command not found.\n");
    }
}

int fault_error(init_t *init)
{
    if (WTERMSIG(init->status) == 8) {
        if (WCOREDUMP(init->status))
            my_putstr("Floating exception (core dumped)\n");
        else
            my_putstr("Floating exception\n");
        return 1;
    }
    if (WCOREDUMP(init->status))
        my_putstr("Segmentation fault (core dumped)\n");
    else
        my_putstr("Segmentation fault\n");
    return 1;
}
