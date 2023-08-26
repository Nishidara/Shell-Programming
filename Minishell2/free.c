/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-elias.abassi
** File description:
** idk
*/

#include "include/my.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++){
        free(tab[i]);
    }
    free(tab);
}

void free_triple_tab(char ***tab)
{
    for (int i = 0; tab[i] != NULL; i++){
        free_tab(tab[i]);
    }
}

void free_all_exec_bis(init_t *init, char* tmp, char **env)
{
    if (init->cpy_env != env)
        free_tab(init->cpy_env);
    free(init);
    free(tmp);
    exit(1);
}

void free_all_exec(init_t *init, char ***tab, char **tab2)
{
    struct stat directory;
    stat(tab[init->x][0], &directory);

    if (S_ISDIR(directory.st_mode)) {
        my_putstr(tab[init->x][0]);
        my_putstr(": Permission denied.\n");
    } else if (errno == ENOEXEC) {
        my_putstr(tab[init->x][0]);
        my_putstr(": Exec format error. Wrong Architecture.\n");
    } else {
        not_found(init, tab);
    }
    free(init->str);
    free_triple_tab(tab);
    free_tab(tab2);
}
