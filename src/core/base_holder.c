/*
** base_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 10:29:25 2016 romain pillot
** Last update Wed Nov  2 01:50:01 2016 romain pillot
*/

#include "utils.h"
#include "base_holder.h"
#include <stdlib.h>

static t_base	*private_base(t_base **base)
{
  static t_base	*singleton;

  if (base && *base)
    singleton = *base;
  return (singleton);
}

int		get_decimal(char c)
{
  int		index;
  char		*charset;

  charset = private_base(0)->charset;
  index = 0;
  while (c != charset[index++]);
  return (index - 1);
}

char	get_char(int decimal)
{
  return (private_base(0)->charset[decimal - 1]);
}

t_base	*get_base()
{
  return (private_base(0));
}

char		build_base(char **charset)
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
  private_base(&base);
  return (1);
}
