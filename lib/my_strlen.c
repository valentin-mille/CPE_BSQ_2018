/*
** EPITECH PROJECT, 2018
** CPool_bistro-matic_2018
** File description:
** my_strlen
*/

#include "../include/lib.h"

int my_strlen(char const *str)
{
    int counter = 0;

    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}
