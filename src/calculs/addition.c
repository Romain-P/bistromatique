/*
** operations.c for infin_add in /home/antonin.rapini/CPool_infinadd
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Oct 25 16:00:17 2016 Antonin Rapini
** Last update Sat Nov  5 01:04:42 2016 romain pillot
*/

#include "number.h"
#include <stdlib.h>
#include "utils.h"

t_number	*create_addition_result(t_number **a, t_number **b)
{
  t_number	*temp;

  if(!is_greater((*a), (*b)))
    {
      temp = (*a);
      (*a) = (*b);
      (*b) = temp;
    }
  return (create_result((*a)->size + 1, (*a)->sign));
}

void	addition(t_number *a, t_number *b, t_number *result, t_base *base)
{
  int	index;
  int	holder;
  int	retenue;

  retenue = 0;
  index = a->size - 1;
  while (index >= 0)
    {
      holder = (index < a->size - b->size) ?
	0 : (b->get[index - (a->size - b->size)] - 48) * b->sign;
      holder = (a->get[index] - 48) + (holder * result->sign) + retenue;
      retenue = (holder < 0) ? -1 : holder / 10;
      result->get[index + 1] = (holder < 0) ? (10 + holder) + '0' : (holder % 10) + '0';
      index = index - 1;
    }
  result->get[0] = (retenue == 1) ? '1' : '0';
}
