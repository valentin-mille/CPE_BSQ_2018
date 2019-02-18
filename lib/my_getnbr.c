/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** function that returns a number, sent to the function as a string.
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;

    while (str [i] != '\0') {
        nb = (nb * 10) + str [i] - 48;
        i++;
    }
    return (nb);
}