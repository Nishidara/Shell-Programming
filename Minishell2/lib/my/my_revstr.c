/*
** EPITECH PROJECT, 2022
** Jour6
** File description:
** my_revstr
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    char c;
    int i = 0;
    int j = my_strlen(str) - 1;

    while (i < j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}
