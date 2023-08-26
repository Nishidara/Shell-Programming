/*
** EPITECH PROJECT, 2022
** Jour6
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    while (s1[a] != '\0') {
        if (s1[a] != s2[a]) {
            return (s2[a] - s1[a]);
        }
        a++;
    }
    return (s1[a] - s2[a]);
}
