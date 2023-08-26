/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-elias.abassi
** File description:
** my_carac_isnum
*/

int my_carac_isnum(char carac)
{
    if (carac < '0' || carac > '9')
        return 0;
    return 1;
}
