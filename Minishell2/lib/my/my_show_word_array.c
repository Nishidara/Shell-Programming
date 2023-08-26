/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-elias.abassi
** File description:
** my_show_word_array
*/

#include <stddef.h>

void my_putchar(char c);
void my_putstr(char *str);

int my_show_word_array(char * const *tab)
{
    if (tab == NULL || tab[0] == NULL)
        return 0;
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
