/*
** EPITECH PROJECT, 2018
** my_put_functions
** File description:
** put functions for my_ls
*/
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int    my_putstr(char const *str)
{
    int a;

    a = 0;
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a = a + 1;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb < 0)
    {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    nb = (nb % 10);
    if (nb >= 0 && nb <= 9)
    {
        my_putchar(nb + '0');
    }
    return (nb);
}