/*
** division.c for bistromatique in /home/raphael.goulmot/rendu/bistromatique/src/calculs
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon Oct 31 14:37:28 2016 Raphaël Goulmot
** Last update Fri Nov  4 19:41:34 2016 Antonin Rapini
*/

#include "operations.h"
#include "number.h"
#include <stdlib.h>
#include "operations_helpers.h"
#include "utils.h"

t_number        *create_modulo_result(t_number **a, t_number **b)
{
  int           index;

  if (is_zero((*b)->get))
    {
      my_putstr("Modulo by zero\n");
      exit(84);
    }
  return (create_result((*a)->size, (*a)->sign));
}

void            modulo(t_number *a, t_number *b, t_number *c, t_base *base)
{
  int           count;
  t_number      *b_temp;
  t_number      *a_temp;

  count = 0;
  b_temp = create_result(a->size, -1);
  fill_result('0', b_temp);
  while (count++ < b->size)
    b_temp->get[count - 1] = b->get[count - 1];
  while (!is_greater(b, a))
    {
      while (!is_greater(b_temp, a))
	{
	  a_temp = create_result(a->size + 1, 1);
	  fill_result('0', a_temp);
	  addition(a, b_temp, a_temp);
	  a->size = a_temp->size;
	  copy_smaller_nbr(a_temp->get, a);
	  free(a_temp);
	}
      b_temp->size--;
      b_temp->get[b_temp->size] = '\0';
    }
  copy_smaller_nbr(a->get, c);
  free(b_temp);
}
