/*
** EPITECH PROJECT, 2022
** Jour5
** File description:
** my_compute_power_rec
*/

void my_putchar(char c);

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    if (p > 0)
        nb *= my_compute_power_rec(nb, p - 1);
    else
        return 1;
    return (nb);
}
