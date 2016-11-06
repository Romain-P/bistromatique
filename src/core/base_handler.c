/*
** base_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 10:29:25 2016 romain pillot
** Last update Sun Nov  6 18:30:43 2016 Antonin Rapini
*/

#include "base_handler.h"
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "constants.h"

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
  my_putstr_err(SYNTAX_ERROR_MSG);
  return (0);
}

char	get_char(t_base *base, int decimal)
{
  return (base->charset[decimal]);
}

t_base		*build_base(char **charset)
{
  int		index;
  int		index2;
  t_base	*base;

  index = 0;
  while ((*charset)[index++])
    {
      index2 = index;
      while ((*charset)[index2++])
	if ((*charset)[index - 1] == (*charset)[index2 - 1])
	  return (0);
    }
  base = malloc(sizeof(t_base));
  base->size = index - 1;
  base->charset = *charset;
  return (base);
}
