/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** Find the largest possible square on a board while avoiding obstacles
*/

#include "../include/lib.h"

int pass_first_line(int fd)
{
    char cursor;

    while (cursor != '\n') {
        read(fd, &cursor, 1);
    }
    return 0;
}

int check_nb_cols(int fd)
{
    int counter = 0;
    char cursor;

    while (cursor != '\n') {
        read(fd, &cursor, 1);
    }
    read(fd, &cursor, 1);
    while (cursor != '\n') {
        read(fd, &cursor, 1);
        counter++;
    }
    close(fd);
    return counter;
}

int **get_the_content_folder(char *filepath, int fd, stats_t *map)
{
    number_t *position = malloc(sizeof(number_t));
    int **stocker;

    stocker = malloc(sizeof(int *) * map->nb_rowls + 2);
    fd = open(filepath, O_RDONLY);
    pass_first_line(fd);
    check_square(map, position, stocker, fd);
    close (fd);
    print_folder_with_square(get_map(filepath, map), position, map);
    return (stocker);
}

int do_bsq(char **av)
{
    stats_t *map = malloc(sizeof(stats_t));
    int fd = open(av[1], O_RDONLY);

    map->nb_rowls = fs_get_number_from_first_line(av[1]);
    map->nb_cols = check_nb_cols(fd);
    get_the_content_folder(av[1], fd, map);
    close (fd);
    return 0;
}