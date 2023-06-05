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
		parsing.c	\

TST =	my_printf/my_strlen.c	\
		my_printf/my_putchar.c	\
		my_printf/my_putstr.c	\
		my_printf/my_putnbr.c	\
		my_printf/my_getnbr.c	\
		my_printf/my_strcmp.c	\

STST =	tests/test_my_strlen.c	\
		tests/test_my_putstr.c	\
		tests/test_my_getnbr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
NC=\033[0m

all: $(NAME)

$(NAME):
	@echo -e "${CYAN}"
	@cat banner.txt
	@echo -e "${NC}"
	@echo -e "${BLUE}Compiling...${NC}"
	@echo -n 'Progress: ['
	@for i in {1..30}; do \
	    echo -ne "\033[48;5;$$((i+232))m \033[0m"; \
	    sleep 0.09; \
	done
	@echo -e "]"
	@gcc $(SRC) -o $(NAME) -g3 | while read line; do \
		echo -ne "\033[48;5;$$((RANDOM%232+1))m \033[0m"; \
	done
	@echo ''
	@echo -e "${GREEN}[✓] Compilation done.${NC}"

clean:
	@echo -e "${YELLOW}\033[5mCleaning up...${NC}"
	@rm -f $(OBJ)
	@echo -e "${GREEN}\033[5m[✓] Cleaning up done.${NC}"

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f *#
	@rm -f unit_tests
	@rm -f *.gcda
	@rm -f *.gcno
	@find . -name "*.o" -type f -delete
	@echo -e "${GREEN}\033[5m[✓] Full clean done.${NC}"

re: fclean all

tests_run: $(OBJ)
	@echo -e "${MAGENTA}\033[5mRunning unit tests...${NC}"
	@gcc -o unit_tests $(TST) $(STST) --coverage -lcriterion
	./unit_tests
	@echo -e "${GREEN}\033[5m[✓] Unit tests passed.${NC}"

blink_file:
	@echo -e "${YELLOW}\033[5m"
	@cat /home/dshalom/B-CPE-200-COT-2-1-dante-shalom.dosseh/banner.txt
	@echo -e "${NC}"
