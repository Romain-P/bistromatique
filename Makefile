##
## Makefile for bistromatique in /home/romain.pillot/github/bistromatique
## 
## Made by Romain Pillot
## Login   <romain.pillot@epitech.net>
## 
## Started on  Sat Oct 15 15:17:21 2016 romain pillot
## Last update Wed Nov  2 15:25:44 2016 Raphaël Goulmot
#

RM	=	rm

NAME	=	calc

SRC     =	src/core/main.c			\
		src/core/syntax_holder.c	\
		src/core/base_holder.c		\
		src/parser/calculator.c		\
		src/struct/number.c		\
		src/util/my_putstr.c		\
		src/util/my_strlen.c		\
		src/util/my_putchar.c		\
		src/util/my_isgreater.c

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
