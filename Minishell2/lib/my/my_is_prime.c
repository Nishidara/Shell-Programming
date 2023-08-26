/*
** EPITECH PROJECT, 2022
** Jour5
** File description:
** my_is_prime
*/

void my_putchar(char c);

int my_is_primesuite(int nb)
{
    if (nb < 2) {
        return 0;
    } else if (nb == 2) {
        return 1;
    }
    return 0;
}

void my_is_primesuite2(int nb)
{
    int i = 1;

    while (i * i <= nb) {
        if (nb % i == 0)
            return;
        i = i + 2;
    }
}

int my_is_prime(int nb)
{
    int i;

    my_is_primesuite(nb);
    if (nb % 2 == 0) {
        return 0;
    } else {
        i = 3;
        my_is_primesuite2(nb);
    }
    return 1;
}
