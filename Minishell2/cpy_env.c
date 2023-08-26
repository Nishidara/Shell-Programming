/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-elias.abassi
** File description:
** cpy_env
*/

#include "include/my.h"

int buf_cpy_env(init_t *init, char **env)
{
    int i;
    int j;

    for (i = 0; env[i] != NULL; i++);
    char **tmp = malloc(sizeof(char *) * (i + 1));

    for (j = 0; env[j] != NULL; j++) {
        tmp[j] = malloc(sizeof(char) * (my_strlen(env[j]) + 1));
        my_strcpy(tmp[j], env[j]);
    }
    tmp[j] = NULL;
    init->cpy_env = tmp;
    if (init->cpy_env == NULL)
        init->cpy_env = env;
    return 0;
}
