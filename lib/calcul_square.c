/*
** EPITECH PROJECT, 2018
** calcul_square.c
** File description:
** function for the BSQ
*/

#include "../include/lib.h"

int convert_char(char cursor, int fd)
{
    int tmp;

    read(fd, &cursor, 1);
    if (cursor == 'o')
        tmp = 0;
    if (cursor == '.')
        tmp = 1;
    return tmp;
}

char **get_map(char *argu, stats_t *map)
{
    char buffer[map->nb_cols];
    int size = 0;
    int count = 0;
    int fd = open(argu, O_RDONLY);
    char **str;
    str = malloc(sizeof(char *) * map->nb_rowls + 1);

    pass_first_line(fd);
    size = read(fd, buffer, map->nb_cols + 1);
    while (size > 0) {
        str[count] = malloc(sizeof(char) * map->nb_cols + 1);
        buffer[size] = '\0';
        my_strcpy(str[count], buffer);
        size = read(fd, buffer, map->nb_cols + 1);
        ++count;
    }
    return (str);
}

char **print_folder_with_square(char **str, number_t *position, stats_t *map)
{
    int count = 0;
    int i = 0;

    if (str[count][i] == '.')
        str[count][i] = 'x';
    while (count < position->maxi_square) {
        i = 0;
        while (i < position->maxi_square) {
            str[position->y - count][position->x - i] = 'x';
            ++i;
        }
        ++count;
    }
    print_map(str, map);
    return (str);
}

char **print_map(char **str, stats_t *map)
{
    int count;

    for (count = 0; count < map->nb_rowls; ++count) {
        my_putstr(str[count]);
    }
    return (str);
}

int do_sum_digit(int top_left, int top, int left, int nb)
{
    int min;
    int sum;

    if (top_left < top)
        min = top_left;
    else
        min = top;
    if (left < min) {
        sum = left;
    }
    else
        sum = min;
    if (nb == 0)
        sum = 0;
    else
        sum = 1 + sum;
    return sum;
}