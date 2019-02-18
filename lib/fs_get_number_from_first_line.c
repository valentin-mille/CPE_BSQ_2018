/*
** EPITECH PROJECT, 2018
** fs_get_number_from_first_line.c
** File description:
** function that retrieve and return the posiive number
*/

#include "../include/lib.h"

int display_error(char str)
{
    if (str == '-') {
        write(2, "Error the number is negative", 29);
        return -1;
    }
    if (str < '0' && str > '9') {
        write(2, "Error there is no number", 25);
        return 84;
    }
    return 0;
}

int fs_get_number_from_first_line(char const *filepath)
{
    int count = 0;
    int fd;
    char buffer[500];
    char *number = malloc(100);

    fd = open(filepath, O_RDONLY);
    read(fd, buffer, 500);
    while (buffer[count] != '\n')
    {
        display_error(buffer[count]);
        number[count] = buffer[count];
        count++;
    }
    close (fd);
    if (my_getnbr(number) == 0) {
        write(2, "Error there is no number", 25);
        return 84;
    }
    return (my_getnbr(number));
}

void get_square_position(number_t * position, int **stocker, int count, int i)
{
    if (i > 0 && position->maxi_square < stocker[count][i]) {
        position->maxi_square = stocker[count][i];
        position->x = i;
        position->y = count;
    }
}

void check_square(stats_t *map, number_t *position, int **stocker, int fd)
{
    int count = 0;
    char cursor;
    int i;
    int sum = 0;

    while (count < map->nb_rowls) {
        stocker[count] = malloc(sizeof(int) * map->nb_cols + 1);
        i = 0;
        while (i < map->nb_cols) {
            stocker[count][i] = convert_char(cursor, fd);
            if (count > 0) {
                call_sum(sum, stocker, count, i);
                get_square_position(position, stocker, count, i);
            }
            ++i;
        }
        read(fd, &cursor, 1);
        count++;
    }
}

int **call_sum(int sum, int **stocker, int count, int i)
{
    sum = do_sum_digit(stocker[count - 1][i - 1],
    stocker[count - 1][i], stocker[count][i - 1],
    stocker[count][i]);
    stocker[count][i] = sum;
    return stocker;
}