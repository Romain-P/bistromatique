/*
** operations.c for infin_add in /home/antonin.rapini/CPool_infinadd
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Oct 25 16:00:17 2016 Antonin Rapini
** Last update Sun Nov  6 11:52:44 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"

t_number	*create_multiplication_result(t_number **a, t_number **b, t_base *base)
{
  int		sign;

  sign = ((*a)->sign == -1 || (*b)->sign == -1) &&
    !((*a)->sign == -1 && (*b)->sign == -1) ? -1 : 1;
  return (create_result((*a)->size + (*b)->size + 1, sign));
}

void	multiplication(t_number *a, t_number *b, t_number *result, t_base *base)
{
  int	a_index;
  int	b_index;
  int	result_index;
  int	holder;

  result_index = 0;
  a_index = a->size - 1;
  b_index = b->size - 1;
  while (a_index >= 0)
    {
      holder = get_decimal(base, a->get[a_index]) * get_decimal(base, b->get[b_index]);
      result_index = result->size - (b->size - b_index) - (a->size - a_index);
      holder = holder + get_decimal(base, result->get[result_index + 1]);
      place_value(holder, result_index + 1, result, base);
      a_index = b_index > 0 ? a_index : a_index - 1;
      b_index = b_index > 0 ? b_index - 1 : b->size - 1;
    }
}
