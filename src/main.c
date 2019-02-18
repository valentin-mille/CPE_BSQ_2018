/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for the bsq program
*/

#include "../include/lib.h"

int main(int ac, char **av)
{
    int program = 84;
    int fd = open(av[1], O_RDONLY);

    if (ac != 2) {
        write(2, "Error argument.\n", 17);
        return (program);
    }
    else if (fd == -1) {
        write(2, "File can't be opened.\n", 23);
        return program;
    } else {
        do_bsq(av);
        program = 0;
    }
    return program;
}