/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-elias.abassi
** File description:
** my
*/

#ifndef __MY_H__
    #define __MY_H__

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>
    #include <stddef.h>
    #include <sys/wait.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <assert.h>

    void my_putchar(char c);
    int my_putstr(char *str);
    int my_strlen(char const *str);
    void my_put_nbr(int nb);
    int my_getnbr(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int nb);
    char **my_str_to_word_array(char *str, char *lim);
    char *my_strcat(char *dest, char const *src);
    char *my_strcpy(char *dest, char const *src);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_carac_isalpha(char carac);
    int my_carac_isnum(char carac);

    typedef struct init {
        int x;
        int status;
        int error_output;
        char *str;
        char **cpy_env;
    } init_t;

    int buf_cpy_env(init_t *init, char **env);

    char *echo_case(init_t *init, size_t size);
    int show_loc(size_t size);

    void check_exit(init_t *init, char **tab3, char **env, char ***tab);
    int differencies(init_t *init, char ***tab, char **env);

    int do_cd(init_t *init, char ***tab);
    void print_env(init_t *init);
    pid_t do_bin(init_t *init, char ***tab, char **env);
    int my_setenv(init_t *init, char ***tab);
    int my_unsetenv(init_t *init, char ***tab);

    void not_found(init_t *init, char ***tab);
    int fault_error(init_t *init);

    void free_tab(char **tab);
    void free_triple_tab(char ***tab);
    void free_all_exec(init_t *init, char ***tab, char **tab2);
    void free_all_exec_bis(init_t *init, char* tmp, char **env);

#endif
