/*
** EPITECH PROJECT, 2022
** Jour6
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i <= n) {
        dest[i] = '\0';
    }
    return (dest);
}
