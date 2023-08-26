/*
** EPITECH PROJECT, 2022
** Jour6
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    int	i;

    i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
            i = i + 1;
        else
            return 0;
    }
    return 1;
}
