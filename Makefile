##
## Makefile for bistromatique in /home/romain.pillot/github/bistromatique
## 
## Made by Romain Pillot
## Login   <romain.pillot@epitech.net>
## 
## Started on  Sat Oct 15 15:17:21 2016 romain pillot
## Last update Fri Oct 28 05:13:37 2016 romain pillot
#

RM	=	rm

NAME	=	calc

SRC     =	src/core/main.c	\
		src/utils/my_putstr.c	\
		src/utils/my_strlen.c	\
		src/utils/my_putchar.c

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
