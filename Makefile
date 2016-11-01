##
## Makefile for bistromatique in /home/romain.pillot/github/bistromatique
## 
## Made by Romain Pillot
## Login   <romain.pillot@epitech.net>
## 
## Started on  Sat Oct 15 15:17:21 2016 romain pillot
## Last update Tue Nov  1 12:52:26 2016 romain pillot
#

RM	=	rm

NAME	=	calc

SRC     =	src/core/main.c			\
		src/core/syntax_holder.c	\
		src/core/base_holder.c		\
		src/parser/checker.c		\
		src/struct/number.c		\
		src/utils/my_putstr.c		\
		src/utils/my_strlen.c		\
		src/utils/my_putchar.c		\
		src/utils/my_isgreater.c

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
