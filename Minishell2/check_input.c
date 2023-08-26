/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-elias.abassi
** File description:
** check_input
*/

#include "include/my.h"

void check_for_bin(init_t *init, char ***tab, char **env)
{
    init->status = 0;
    waitpid(do_bin(init, tab, env), &init->status, 0);
    if (WIFSIGNALED(init->status))
        fault_error(init);
}

int differencies(init_t *init, char ***tab, char **env)
{
    if (my_strncmp(tab[init->x][0], "cd", 2) == 0) {
        do_cd(init, tab);
        return 0;
    }
    if (my_strncmp(tab[init->x][0], "env", 3) == 0) {
        print_env(init);
        return 0;
    }
    if (my_strncmp(tab[init->x][0], "setenv", 6) == 0) {
        my_setenv(init, tab);
        return 0;
    }
    if (my_strncmp(tab[init->x][0], "unsetenv", 8) == 0) {
        my_unsetenv(init, tab);
        return 0;
    } else
        check_for_bin(init, tab, env);
    return 0;
}
