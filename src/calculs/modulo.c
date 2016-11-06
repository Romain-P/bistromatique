/*
** division.c for bistromatique in /home/raphael.goulmot/rendu/bistromatique/src/calculs
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon Oct 31 14:37:28 2016 Raphaël Goulmot
** Last update Sun Nov  6 21:13:26 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "calculs.h"
#include "utils.h"
#include "constants.h"

t_number        *create_modulo_result(t_number **a, t_number **b, t_base *base)
{
  if (is_zero(base->charset[0], (*b)->get))
      my_putstr_err(ERROR_MSG);
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
  while (!is_greater(b, a, base))
    {
      while (!is_greater(b_temp, a, base))
	{
	  a_temp = create_result(a->size + 1, 1);
	  fill_result(base->charset[0], a_temp);
	  addition(a, b_temp, a_temp, base);
	  a->size = a_temp->size;
	  copy_smaller_nbr(base->charset[0], a_temp->get, a);
	  free(a_temp);
	}
      b_temp->size--;
      b_temp->get[b_temp->size] = '\0';
    }
  copy_smaller_nbr(base->charset[0], a->get, c);
  free(b_temp);
}
