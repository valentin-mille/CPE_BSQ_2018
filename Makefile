##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC      =           gcc

CFLAGS	=			-Wall -Wextra 

SRC	=				src/bsq.c \
					lib/my_strlen.c \
					lib/my_putchar.c \
					lib/my_putstr.c \
					lib/fs_get_number_from_first_line.c \
					lib/my_getnbr.c \
					lib/my_put_nbr.c \
					lib/calcul_square.c \
					lib/my_strcpy.c \
					src/main.c


OBJ		=			$(SRC:.c=.o)

NAME	=			bsq

all:	$(NAME)

$(NAME):		$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

test:
		$(CC) -o $(NAME) $(OBJ) -lcriterion
		./$(NAME)

clean:
		rm -f **/*.o *.o

fclean: clean
		rm -f $(NAME)

re:		fclean all