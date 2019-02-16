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

int my_put_error(int line, int matches, int limit)
{
    if (matches < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (0);
    }
    else if (matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (0);
    }
    if (matches > limit) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(limit);
        my_putstr(" matches per turn\n");
        return (0);
    }
    else if (matches > line) {
        my_putstr("Error: not enough matches on this line\n");
        return (0);
    }
    return (matches);
}

int *my_arrcpy(int nb, int *src)
{
    int *arr = malloc(sizeof(int) * nb);

    for (int i = 0; i < nb; i = i + 1)
        arr[i] = src[i];
    return (arr);
}