/*
** base_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 10:29:25 2016 romain pillot
** Last update Sat Nov  5 20:46:16 2016 Antonin Rapini
*/

#include "base_handler.h"
#include <stdlib.h>
#include <unistd.h>

int	get_decimal(t_base *base, char c)
{
  int	index;
  char	*charset;

  charset = base->charset;
  index = 0;
  while (charset[index] && c != charset[index])
      index++;
  if (c == charset[index])
    return (index);
  write(1, "Syntax error", 12);
  exit(84);
  return (0);
}

char	get_char(t_base *base, int decimal)
{
  return (base->charset[decimal]);
}

t_base		*build_base(char **charset)
{
  int		index;
  char		tmp;
  t_base	*base;

  index = 0;
  tmp = 0;
  while ((*charset)[index++])
    {
      if (tmp && tmp == (*charset)[index - 1])
	return (0);
      tmp = (*charset)[index - 1];
    }
  base = malloc(sizeof(t_base));
  base->size = index - 1;
  base->charset = *charset;
  return (base);
}
