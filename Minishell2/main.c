/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-elias.abassi
** File description:
** main
*/

#include "include/my.h"

void start_shell(init_t *init, char **tab3, char **env)
{
    int b;
    char ***tab;

    for (b = 0; tab3[b] != NULL; b++);
    tab = malloc(sizeof(char **) * (b + 1));

    for (init->x = 0; tab3[init->x] != NULL; init->x++) {
        tab[init->x] = my_str_to_word_array(tab3[init->x], " \n\t");
        tab[init->x + 1] = NULL;
        if (my_strcmp(tab[init->x][0], "") != 0) {
            check_exit(init, tab3, env, tab);
            differencies(init, tab, env);
        }
    }
    free_triple_tab(tab);
    free_tab(tab3);
    free(init->str);
}

void infinite_loop(init_t *init, char **env)
{
    size_t size;
    init->str = NULL;
    size = 0;
    char **tab3;

    while (1) {
        init->str = echo_case(init, size);
        tab3 = my_str_to_word_array(init->str, ";");
        start_shell(init, tab3, env);
    }
    return;
}

int main(int ac, char **av, char **env)
{
    (void) av;
    init_t *init = malloc(sizeof(init_t));

    buf_cpy_env(init, env);
    if (ac == 1) {
        infinite_loop(init, env);
    if (init->cpy_env != env)
        free_tab(init->cpy_env);
    free(init);
    return 0;
    } else {
    if (init->cpy_env != env)
        free_tab(init->cpy_env);
    free(init);
    return 84;
    }
    return 0;
}
