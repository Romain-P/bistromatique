##
## Makefile for bistromatique in /home/romain.pillot/github/bistromatique
## 
## Made by Romain Pillot
## Login   <romain.pillot@epitech.net>
## 
## Started on  Sat Oct 15 15:17:21 2016 romain pillot
<<<<<<< HEAD
## Last update Thu Nov  3 14:35:18 2016 romain pillot
=======
## Last update Thu Nov  3 01:51:58 2016 Raphaël Goulmot
>>>>>>> c4f28da62bab5e22e07804b2e9c049b397fa8842
#

RM	=	rm

NAME	=	calc

SRC     =	src/core/main.c			\
		src/core/syntax_handler.c	\
		src/core/base_handler.c		\
		src/parser/calculator.c		\
		src/parser/parser.c		\
		src/struct/number.c		\
		src/util/my_putstr.c		\
		src/util/my_strlen.c		\
		src/util/my_putchar.c		\
		src/util/my_isgreater.c		\
		src/util/my_swap.c

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

fclean:	clean
	$(RM) -f $(NAME)

re: fclean all
