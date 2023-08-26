/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-elias.abassi
** File description:
** env
*/

#include "include/my.h"

void for_unsetenv_bis(init_t *init, int i)
{
    for (;init->cpy_env[i + 1] != NULL; i++) {
            init->cpy_env[i] = init->cpy_env[i + 1];
            init->cpy_env[i + 1] = NULL;
    }
}

void for_unsetenv(init_t *init, char ***tab)
{
    for (int i = 0; init->cpy_env[i] != NULL; i++) {
        if (my_strncmp(init->cpy_env[i], tab[init->x][1], \
        my_strlen(tab[init->x][1])) == 0) {
            free(init->cpy_env[i]);
            init->cpy_env[i] = NULL;
            for_unsetenv_bis(init, i);
        }
    }
    return;
}

int my_unsetenv(init_t *init, char ***tab)
{
    if (tab[init->x][1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
    } else {
        for_unsetenv(init, tab);
    }
    return 0;
}
