/*
** EPITECH PROJECT, 2022
** Jour5
** File description:
** my_find_prime_sup
*/

void my_putchar(char c);
int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb > 2 && nb % 2 == 0)
        nb++;
    while (!my_is_prime(nb)) {
        nb = nb + 2;
    }
    return (nb);
}
