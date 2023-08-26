/*
** EPITECH PROJECT, 2022
** Jour3
** File description:
** my_isneg
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else if (n > 0)
        my_putchar('P');
    else
        my_putchar('P');
    my_putchar('\n');
    return 0;
}
