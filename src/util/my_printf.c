/*
** my_printf.c for bistromatique in /home/raphael.goulmot/rendu/bistromatique/src/util
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Thu Nov  3 01:57:07 2016 Raphaël Goulmot
** Last update Sun Nov  6 21:10:54 2016 Antonin Rapini
*/

#include <stdio.h>
#include <stdarg.h>
#include "utils.h"

void	my_printf(char *str, ...)
{
  va_list	args;

  va_start(args, str);
  while (*str)
    {
      if (*str == '%')
	{
	  str++;
	  if (*str == 'c')
	    my_putchar(va_arg(args, int));
	  else if (*str == 's')
	    my_putstr(va_arg(args, char *));
	  else if (*str == 'd')
	    my_put_nbr(va_arg(args, int));
	}
      else
	my_putchar(*str);
      str++;
    }
  va_end(args);
}
