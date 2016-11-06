/*
** operations.c for infin_add in /home/antonin.rapini/CPool_infinadd
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Oct 25 16:00:17 2016 Antonin Rapini
** Last update Sun Nov  6 11:39:46 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "operations_helpers.h"
#include "utils.h"
#include "calculs.h"

t_number	*create_addition_result(t_number **a, t_number **b, t_base *base)
{
  t_number	*temp;

  if(is_greater((*b), (*a), base))
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
	0 : get_decimal(base, b->get[index - (a->size - b->size)]) * b->sign;
      holder = get_decimal(base, a->get[index]) + (holder * result->sign) + retenue;
      retenue = (holder < 0) ? -1 : holder / base->size;
		result->get[index + 1] = (holder < 0) ? get_char(base, base->size + holder) : get_char(base, holder % base->size);
      index = index - 1;
    }
  result->get[0] = (retenue > 0) ? base->charset[1] : base->charset[0];
}
