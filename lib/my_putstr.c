/*
** EPITECH PROJECT, 2018
** CPool_bistro-matic_2018
** File description:
** my_putstr
*/

#include "../include/lib.h"

int my_putstr(char const *str)
{
    int counter = 0;

    while (str[counter] != 0) {
        my_putchar(str[counter]);
        counter++;
    }
    return 0;
}