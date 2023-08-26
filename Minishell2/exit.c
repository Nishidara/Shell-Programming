/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-elias.abassi
** File description:
** exit
*/

#include "include/my.h"

void check_exit(init_t *init, char **tab3, char **env, char ***tab)
{
    if (my_strcmp(tab[init->x][0], "exit") == 0) {
        my_putstr("exit\n");
        free_triple_tab(tab);
        free_tab(tab3);
        free(init->str);
        if (init->cpy_env == NULL)
            init->cpy_env = env;
        free(init);
        exit(0);
    }
}
