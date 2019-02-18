/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** function that displays the number given as a parameter.
*/

#include <unistd.h>
#include "../include/lib.h"

int my_put_nbr(int nb)
{
    int first_nb = nb;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    first_nb = nb % 10 + '0';
    my_putchar(first_nb);
    return (0);
}