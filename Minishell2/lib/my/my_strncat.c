/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday07-elias.abassi
** File description:
** my_strncat
*/

int my_strlen(char *str);

char *my_strncat(char *dest, char *src, int nb)
{
    int len = my_strlen(dest);
    int a = 0;

    while (a < nb && src[a] != '\0') {
        dest[len + a] = src[a];
        a++;
    }
    dest[len + a] = '\0';
    return (dest);
}
