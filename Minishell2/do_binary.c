/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-elias.abassi
** File description:
** do_binaire
*/

#include "include/my.h"

char *for_bin_bis(init_t *init, int i, int j, char *tmp)
{
    int env_PATH;

    for (env_PATH = 5; init->cpy_env[i][env_PATH] != '\0'; env_PATH++) {
        tmp[j] = init->cpy_env[i][env_PATH];
        j++;
    }
    tmp[j] = '\0';
    return (tmp);
}

char *for_bin(init_t *init)
{
    char *tmp;
    int j = 0;

    for (int i = 0; init->cpy_env[i] != NULL; i++) {
        if (my_strncmp(init->cpy_env[i], "PATH=", 5) == 0) {
            tmp = malloc(sizeof(char) * (my_strlen(init->cpy_env[i]) - 4));
            for_bin_bis(init, i, j, tmp);
        }
    }
    return (tmp);
}

void exec_all_path(init_t *init, char ***tab, char **tab2)
{
    for (int i = 0; tab2[i] != NULL ; i++) {
        char *exec = malloc(sizeof(char) * (my_strlen(tab[init->x][0]) + \
        (my_strlen(tab2[i]) + 2)));
        my_strcpy(exec, tab2[i]);
        my_strcat(exec, "/");
        my_strcat(exec, tab[init->x][0]);
        execve(exec, tab[init->x], init->cpy_env);
        free(exec);
    }
}

pid_t do_bin(init_t *init, char ***tab, char **env)
{
    pid_t pid = fork();
    char *tmp = for_bin(init);
    char **tab2 = my_str_to_word_array(tmp, ":");
    if (pid == 0) {
        exec_all_path(init, tab, tab2);
        execve(tab[init->x][0], tab[init->x], init->cpy_env);
        free_all_exec(init, tab, tab2);
        free_all_exec_bis(init, tmp, env);
    }
    free_tab(tab2);
    free(tmp);
    return pid;
}
