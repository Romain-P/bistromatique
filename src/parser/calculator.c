/*
** checker.c for  in /home/romain.pillot/github/bistromatique/src/parser
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Oct 31 14:17:46 2016 romain pillot
** Last update Tue Nov  1 23:06:19 2016 romain pillot
*/

#include "utils.h"
#include "calculs.h"
#include "syntax_holder.h"

static void (*const operate[5])(t_number *, t_number *, t_number *) = {
  &addition, &addition, &multiplication, &division, &modulo
};

static t_number *(*const allocate[5])(t_number *, t_number *) = {
  &create_addition_result, &create_multiplication_result,
  &create_division_result, &create_modulo_result
};

t_number	*calculate(t_number *a, t_number *b, char operator)
{
  t_number	*result;
  int		index;
  
  if (is_greater(b, a))
    {
      result = a;
      a = b;
      b = result;
    }
  index = get_stx_index(operator);
  result = (*allocate[index])(a, b);
  (*operate[index])(a, b, result);
  return (result);
}
