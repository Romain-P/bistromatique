/*
** my_isgreater.c for  in /home/romain.pillot/github/bistromatique/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Oct 31 15:38:51 2016 romain pillot
** Last update Tue Nov  1 22:34:46 2016 romain pillot
*/

#include "number.h"

char    is_greater(t_number *a, t_number *b)
{
  int	index;

  index = 0;
  if (a->size != b->size)
    return (a->size > b->size);
  while (index++ < a->size)
    {
      if (a->get[index - 1] > b->get[index - 1])
	return (1);
      else if (a->get[index - 1] < b->get[index - 1])
	return (0);
    }
  return (0);
}
