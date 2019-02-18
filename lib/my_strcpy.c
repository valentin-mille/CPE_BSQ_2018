/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** function that copies a string into another
*/

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        dest [i] = str [i];
        i = i + 1;
    }
    dest [i] = '\0';
    return (dest);
}