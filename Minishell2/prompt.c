/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-elias.abassi
** File description:
** extra_function
*/

#include "include/my.h"

int show_loc(size_t size)
{
    char *path = NULL;
    char *location = NULL;

    location = getcwd(path, size);
    my_putstr("\x1b[0;35m");
    my_putstr("\x1b[1;1m");
    my_putchar('[');
    my_putstr(location);
    my_putstr("]$ ");
    my_putstr("\x1b[0m");
    free(location);
    free(path);
    return 0;
}

char *echo_case(init_t *init, size_t size)
{
    if (isatty(0) == 1) {
        show_loc(size);
    }
    if (getline (&init->str, &size, stdin) == -1) {
        if (isatty(0) == 1) {
            my_putstr("exit\n");
        }
        free(init->str);
        free(init);
        exit (0);
    }
    return (init->str);
}
