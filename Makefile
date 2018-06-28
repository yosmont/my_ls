##
## EPITECH PROJECT, 2017
## makefile cat
## File description:
## build the cat
##

CC	=	gcc

OBJ	=	src/my_putchar.c	\
		src/my_putstr.c	\
		src/my_put_nbr.c	\
		src/my_strlen.c	\
		src/my_nbrlen.c	\
		src/my_strdup.c	\
		src/my_strcat.c	\
		src/my_strncat.c	\
		src/my_strcmp.c	\
		src/flag.c	\
		src/ls_long.c	\
		src/ls_long_two.c	\
		src/display.c	\
		src/sort.c	\
		src/sort_two.c	\
		src/just_a_test.c	\
		src/recu.c	\
		src/precall.c	\
		src/main.c

RM	=	rm -f

NAME	=	my_ls

LIB	=	-lmy -Llib/my/ -Iinclude

COM	=	$(OBJ:.c=.o)

all:	$(COM)
	$(CC) -o $(NAME) $(COM) -Iinclude
	make clean

clean:
	$(RM) $(COM)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
