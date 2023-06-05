##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	main.c	\
	basic1.c	\
	solver.c	\
	errors_gestions.c	\
	basic2.c	\
	parsing.c

TST =	my_printf/my_strlen.c	\
	my_printf/my_putchar.c	\
	my_printf/my_putstr.c	\
	my_printf/my_putnbr.c	\
	my_printf/my_getnbr.c	\
	my_printf/my_strcmp.c

STST =	tests/test_my_strlen.c	\
	tests/test_my_putstr.c	\
	tests/test_my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#
	rm -f unit_tests
	rm -f *.gcda
	rm -f *.gcno
	find . -name "*.o" -type f -delete

re:	fclean	all

tests_run:	$(OBG)
	gcc -o unit_tests $(TST) $(STST) --coverage -lcriterion
	./unit_tests
