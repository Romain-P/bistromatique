/*
** base_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 10:29:25 2016 romain pillot
** Last update Tue Nov  1 14:03:11 2016 romain pillot
*/

#include "utils.h"

static char	*private_base(char **str)
{
  static char	*base;

  if (str && *str)
      base = *str;
  return (base);
}

char	*get_base()
{
  return (private_base(0));
}

char	build_base(char **str)
{
  int	index;
  char	tmp;

  index = 0;
  tmp = 0;
  while ((*str)[index++])
    {
      if (tmp && tmp == (*str)[index - 1])
	return (0);
      tmp = (*str)[index - 1];
    }
  private_base(str);
  return (1);
}
