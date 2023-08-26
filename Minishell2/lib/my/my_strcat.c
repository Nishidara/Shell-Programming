/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday07-elias.abassi
** File description:
** my_strcat
*/

int my_strlen(char *str);

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int a = 0;

    while (src[a] != '\0') {
        dest[len] = src[a];
        len++;
        a++;
    }
    dest[len] = '\0';
    return (dest);
}
