/*
** my_isgreater.c for  in /home/romain.pillot/github/bistromatique/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Oct 31 15:38:51 2016 romain pillot
** Last update Sat Nov  5 20:36:33 2016 Antonin Rapini
*/

#include "number.h"
#include "base_handler.h"

char    is_greater(t_number *a, t_number *b, t_base *base)
{
  int	index;

  index = 0;
  if (a->size != b->size)
    return (a->size > b->size);
  while (index++ < a->size)
    {
      if (get_decimal(base, a->get[index - 1]) != get_decimal(base , b->get[index - 1]))
	return (get_decimal(base, a->get[index - 1]) > get_decimal(base, b->get[index - 1]));
    }
  return (0);
}
