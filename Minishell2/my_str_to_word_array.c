/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-elias.abassi
** File description:
** my_str_to_word_array
*/

#include "include/my.h"

int	delim(char c, char *unt)
{
    int i = 0;

    while (unt[i]) {
        if (c == unt[i])
            return (-1);
        i++;
    }
    return (0);
}

int	loop_delim(char const *str, int i, char *unt)
{
    if (delim(str[i], unt) == -1) {
        while (delim(str[i], unt) == -1)
            i++;
        i--;
    }
    return (i);
}

int nbr_words(char const *str, char *unt)
{
    int i = 0;
    int nbr = 1;

    while (str[i]) {
        i = loop_delim(str, i, unt);
        nbr++;
        i++;
    }
    return (nbr);
}

int	my_putcharlen(char *str, int i, char *unt)
{
    int taille = 0;

    while (delim(str[i], unt) == 0 && str[i]) {
        taille++;
        i++;
    }
    return (taille);
}

char **my_str_to_word_array(char *str, char *unt)
{
    int nbr = nbr_words(str, unt) + 2;
    int a = 0;
    char **tab;
    int i = 0;

    tab = malloc(sizeof(char*) * nbr + 1);
    while (str[a]) {
        int j = 0;
        for (a = a; (delim(str[a], unt) == -1 && str[a]); a++);
        tab[i] = malloc(sizeof(char) * (my_putcharlen(str, a, unt) + 1));
        for (a = a; delim(str[a], unt) == 0 && str[a]; a++ , j++)
        tab[i][j] = str[a];
        tab[i][j] = '\0';
            i++;
        for (a = a; (delim(str[a], unt) == -1 && str[a]); a++);
        }
    tab[i] = NULL;
    return (tab);
}
