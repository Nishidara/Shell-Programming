/*
** EPITECH PROJECT, 2022
** Jour5
** File description:
** my_compute_square_root
*/

void my_putchar(char c);

int my_compute_square_root(int nb)
{
    int c = 0;

    if (nb <= 0)
        return 0;
    while (c * c != nb) {
        c++;
        if (c > nb)
            return 0;
    }
    return c;
}
