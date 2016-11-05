/*
** division.c for bistromatique in /home/raphael.goulmot/rendu/bistromatique/src/calculs
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon Oct 31 14:37:28 2016 Raphaël Goulmot
** Last update Sat Nov  5 01:04:53 2016 romain pillot
*/

#include "operations.h"
#include "number.h"
#include <stdlib.h>
#include "utils.h"

t_number	*create_division_result(t_number **a, t_number **b)
{
  int		index;
  int		result_size;
  int		sign;

  if (is_zero((*b)->get))
    {
      my_putstr("Division by zero\n");
      exit(84);
    }
  index = 0;
  while ((*b)->get[index] && (*a)->get[index] && (*a)->get[index] == (*b)->get[index])
    index++;
  result_size = (*a)->get[index] < (*b)->get[index] && (*a)->size - (*b)->size != 0 ?
    (*a)->size - (*b)->size : (*a)->size - (*b)->size + 1;
  result_size = result_size <= 0 ? 1 : result_size;
  sign = ((*a)->sign < 0 || (*b)->sign < 0) && !((*a)->sign < 0 && (*b)->sign < 0) ?
    -1 : 1;
  return (create_result(result_size, sign));
}

void		division(t_number *a, t_number *b, t_number *c, t_base *base)
{
  int		count;
  t_number	*b_temp;
  t_number	*a_temp;

  count = 0;
  b_temp = create_result(a->size, -1);
  fill_result('0', b_temp);
  while (count++ < b->size)
    b_temp->get[count - 1] = b->get[count - 1];
  while (!is_greater(b, a))
    {
      count = 0;
      while (!is_greater(b_temp, a))
	{
	  a_temp = create_result(a->size + 1, 1);
	  fill_result('0', a_temp);
	  addition(a, b_temp, a_temp);
	  a->size = a_temp->size;
	  copy_smaller_nbr(a_temp->get, a);
	  count++;
	  free(a_temp);
	}
      count = count + c->get[c->size - (b_temp->size - b->size) - 1] - '0';
      place_value(count, c->size - (b_temp->size - b->size) - 1, c);
      b_temp->get[b_temp->size--] = 0;
    }
  free(b_temp);
}
