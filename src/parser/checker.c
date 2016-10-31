/*
** checker.c for  in /home/romain.pillot/github/bistromatique/src/parser
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Oct 31 14:17:46 2016 romain pillot
** Last update Mon Oct 31 17:26:10 2016 romain pillot
*/

#include "utils.h"

t_number	*calculate(t_number *a,
			   t_number *b,
			   char operator)
{
  t_number	*result;

  if (is_greater(a, b))
    {
      result = a;
      a = b;
      b = result;
    }
  result = 0;//todo function pointers (allocate_memory)
  //todo function pointers (calcul)
  return (result);
}
