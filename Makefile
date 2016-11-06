##
## Makefile for bistromatique in /home/romain.pillot/github/bistromatique
## 
## Made by Romain Pillot
## Login   <romain.pillot@epitech.net>
## 
## Started on  Sat Oct 15 15:17:21 2016 romain pillot
## Last update Sun Nov  6 18:10:30 2016 Raphaël Goulmot

RM	=	rm

NAME	=	calc

SRC     =	src/core/main.c			\
		src/core/syntax_handler.c	\
		src/core/base_handler.c		\
		src/parser/calculator.c		\
		src/parser/parser.c		\
		src/calculs/addition.c		\
		src/calculs/division.c		\
		src/calculs/modulo.c		\
		src/calculs/multiplication.c	\
		src/struct/number.c		\
		src/struct/node.c		\
		src/struct/operands.c		\
		src/util/my_putstr.c		\
		src/util/my_strlen.c		\
		src/util/my_putchar.c		\
		src/util/my_isgreater.c		\
		src/util/my_swap.c		\
		src/util/my_getnbr.c		\
		src/util/place_value.c		\
		src/util/is_zero.c		\
		src/util/copy_smaller_nbr.c	\
		src/util/my_put_nbr.c		\
		src/util/my_printf.c		\
		src/util/my_putstr_err.c

OBJS	=	$(SRC:.c=.o)

TMP	=	$(SRC:.c=.c~)

CFLAGS	=	-Wextra -Wall -Werror -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

clean:
	$(RM) -f $(OBJS)
	$(RM) -f $(TMP)
	$(RM) -f Makefile~
	clear

fclean:	clean
	$(RM) -f $(NAME)

re: fclean all
