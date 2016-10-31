/*
** division.c for bistromatique in /home/raphael.goulmot/rendu/bistromatique/src/calculs
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon Oct 31 14:37:28 2016 Raphaël Goulmot
** Last update Mon Oct 31 17:42:30 2016 Raphaël Goulmot
*/

#include "division.h"
#include "number.h"
#include <stdlib.h>

void	division(t_number *a, t_number *b, t_number *c)
{
  char	first;
  int	index;

  index = 0;
  first = 1;
  a->sign = 0;
  b->sign = 0;
  while (!a->sign)
    {
      soustraction(a, b, a);
      if (!a->sign)
	{
	  c->get[index] = c->get[index] == 0 ? 49 : c->get[index] + 1;
	  while (c->get[index++] > 57)
	    c->get[index] = 48;
	  c->get[index] = c->get[index] == 0 && index != 0
	    ? 49 : c->get[index] + 1;
	  index = 0;
	}
      c->get[index] = first ? c->get[index] : 48;
      if (first)
	index++;
      first = 0;
    }
  c->get[index] = '\0';
}

t_number	*create_division_result(t_number *a, t_number *b)
{
  int	ia;
  int	ib;

  ia = 0;
  ib = 0;
  while (a[ia++] == b[ab++]);
  ia = a.size - b.size + (b[ib] == '\0' || a[ia] > b[ib] ? 1 : 0);
  return (create_number(malloc(sizeof(char) * (ia + 1))
 , (a->sign == '-' && !b->sign) || (!a->sign && b->sign == '-') ? '-' : '+')));
}
