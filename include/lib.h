/*
** EPITECH PROJECT, 2018
** CPool_bistro-matic_2018
** File description:
** Header for libmy fcts
*/

#ifndef LIB_H_
    #define LIB_H_

    #include <fcntl.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    typedef struct number
    {
        int x;
        int y;
        int maxi_square;
    }number_t;

    typedef struct stats_map
    {
        int nb_cols;
        int nb_rowls;
    } stats_t;

    int fs_get_number_from_first_line(char const *filepath);
    int display_error(char str);
    int my_strlen(char const *str);
    int check_nb_cols(int fd);
    int **get_the_content_folder(char *filepath, int fd, stats_t *map);
    char **print_folder_with_square(char **str, number_t *position,
    stats_t *map);
    char **print_map(char **str, stats_t *map);
    char **get_map(char *argu, stats_t *map);
    void print_cross(int maxi_square, char *filepath);
    int convert_char(char cursor, int fd);
    int pass_first_line(int fd);
    int do_sum_digit(int top_left, int top, int left, int nb);
    int do_bsq(char **av);
    int my_putstr(char const *str);
    void my_putchar(char c);
    int my_getnbr(char const *str);
    char *my_strcpy(char *dest, char const *str);
    int my_put_nbr(int nb);
    int *convert_line_in_digit(char *line, int nb_cols);

    void get_square_position(number_t *position, int **stocker,
    int count, int i);
    int **call_sum(int sum, int **stocker, int count, int i);
    void check_square(stats_t *map, number_t *position, int **stocker, int fd);

#endif