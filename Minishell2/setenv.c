/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-elias.abassi
** File description:
** setenv
*/

#include "include/my.h"

void move_env(init_t *init, char** tmp_env, char ***tab, int j)
{
    int len;

    if (tab[init->x][2] == NULL)
        len = 2;
    else
        len = my_strlen(tab[init->x][2]) + 2;

    tmp_env[j] = malloc(sizeof(char) * (my_strlen(tab[init->x][1]) + len));
    my_strcpy(tmp_env[j], tab[init->x][1]);
    my_strcat(tmp_env[j], "=");

    if (tab[init->x][2] != NULL) {
        my_strcat(tmp_env[j], tab[init->x][2]);
    }
    tmp_env[j + 1] = NULL;
    free(init->cpy_env);
    init->cpy_env = tmp_env;
}

void add_env(init_t *init, char ***tab)
{
    int i;
    int j;
    char *msg = ": Variable name must contain alphanumeric characters.\n";
    char **tmp_env;

    for (int i = 1; tab[init->x][1][i] != '\0'; i++) {
        if (my_carac_isalpha(tab[init->x][1][i]) == 0 && \
        my_carac_isnum(tab[init->x][1][i]) == 0 && tab[init->x][1][i] != '_') {
            my_putstr(tab[init->x][0]);
            my_putstr(msg);
            return;
        }
    }
    for (i = 0; init->cpy_env[i] != NULL; i++);
    tmp_env = malloc(sizeof(char *) * (i + 2));

    for (j = 0; init->cpy_env[j] != NULL; j++) {
        tmp_env[j] = init->cpy_env[j];
    }
    move_env(init, tmp_env, tab, j);
}

int modify_env(init_t *init, char ***tab, int i)
{
    int len;

    if (tab[init->x][2] == NULL)
        len = 2;
    else
        len = my_strlen(tab[init->x][2]) + 2;
    init->cpy_env[i] = NULL;
    init->cpy_env[i] = malloc(sizeof(char) * \
    (my_strlen(tab[init->x][1]) + len));
    my_strcpy(init->cpy_env[i], tab[init->x][1]);
    my_strcat(init->cpy_env[i], "=");
    if (tab[init->x][2] != NULL) {
        my_strcat(init->cpy_env[i], tab[init->x][2]);
    }
    return 0;
}

int for_setenv(init_t *init, char ***tab)
{
    for (int i = 0; init->cpy_env[i] != NULL; i++) {
        if (my_strncmp(init->cpy_env[i], tab[init->x][1], \
        my_strlen(tab[init->x][1])) == 0) {
            modify_env(init, tab, i);
            return 1;
        }
    }
    for (int i = 0; init->cpy_env[i] != NULL; i++) {
        if ((tab[init->x][1][0] >= 'A' && tab[init->x][1][0] <= 'Z') || \
        (tab[init->x][1][0] >= 'a' && tab[init->x][1][0] <= 'z'))
            add_env(init, tab);
        else
            my_putstr("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    return 0;
}

int my_setenv(init_t *init, char ***tab)
{
    int i;

    if (tab[init->x][1] == NULL)
        print_env(init);
    for (i = 0; tab[init->x][i] != NULL; i++);
    if (i > 3)
        my_putstr("setenv: Too many arguments.\n");
    else
        for_setenv(init, tab);
    return 0;
}
