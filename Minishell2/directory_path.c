/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-elias.abassi
** File description:
** check_entries
*/

#include "include/my.h"

char *for_cd_bis(init_t *init, int i, int j, char *tmp)
{
    int env_HOME;

    for (env_HOME = 5; init->cpy_env[i][env_HOME] != '\0'; env_HOME++) {
        tmp[j] = init->cpy_env[i][env_HOME];
        j++;
    }
    tmp[j] = '\0';
    return (tmp);
}

char *for_cd(init_t *init)
{
    char *tmp;
    int j = 0;

    for (int i = 0; init->cpy_env[i] != NULL; i++) {
        if (my_strncmp(init->cpy_env[i], "HOME=", 5) == 0) {
            tmp = malloc(sizeof(char) * (my_strlen(init->cpy_env[i]) - 4));
            for_cd_bis(init, i, j, tmp);
        }
    }
    return (tmp);
}

void if_file(init_t *init, struct stat file, char ***tab)
{
    if (tab[0][1] != NULL) {
        if (S_ISREG(file.st_mode)) {
            my_putstr(tab[0][1]);
            my_putstr(": Not a directory.\n");
        }else
            chdir(tab[init->x][1]);
    }
}

int not_findable(struct stat file, char ***tab)
{
    if (tab[0][1] != NULL ) {
        if (stat(tab[0][1], &file) != 0 && my_strcmp(tab[0][1], "~") != 0) {
            my_putstr(tab[0][1]);
            my_putstr(": No such file or directory.\n");
            return 1;
        }
    }
    return 0;
}

int do_cd(init_t *init, char ***tab)
{
    char *tmp;
    struct stat file;

    if (!tab[init->x][1] || my_strcmp(tab[init->x][1], "~") == 0) {
        tmp = for_cd(init);
        chdir(tmp);
        free(tmp);
        return 0;
    }
    stat(tab[0][1], &file);
    if (not_findable(file, tab) == 1)
        return 0;
    if (my_strcmp(tab[init->x][0], "cd") == 0 \
&& my_strcmp(tab[init->x][1], "~") != 0) {
        if_file(init, file, tab);
    }
    return 0;
}
