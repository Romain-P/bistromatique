/*
** base_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 10:29:25 2016 romain pillot
** Last update Wed Nov  2 21:03:54 2016 romain pillot
*/

#include "utils.h"
#include "base_handler.h"
#include <stdlib.h>

int	get_decimal(t_base *base, char c)
{
  int	index;
  char	*charset;

  charset = base->charset;
  index = 0;
  while (c != charset[index++]);
  return (c == charset[--index] ? index : -1);
}

char	get_char(t_base *base, int decimal)
{
  return (base->charset[decimal - 1]);
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
  base->get = index;
  base->charset = *charset;
  return (base);
}
