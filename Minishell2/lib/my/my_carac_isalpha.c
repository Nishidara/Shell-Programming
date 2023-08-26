/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-elias.abassi
** File description:
** my_carac_isalpha
*/

int my_carac_isalpha(char carac)
{
    int	i;

    if (carac >= 'A' && carac <= 'Z' || carac >= 'a' && carac <= 'z')
        return 1;
    else
        return 0;
    return 1;
}
