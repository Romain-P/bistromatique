/*
** checker.c for  in /home/romain.pillot/github/bistromatique/src/parser
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Oct 31 14:17:46 2016 romain pillot
** Last update Wed Nov  2 21:19:56 2016 romain pillot
*/

#include "utils.h"
#include "calculs.h"
#include "syntax_handler.h"
#include "data.h"

t_number	*calculate(t_operands *ops, t_calcul *calculs, t_data *data)
{
  t_number	*result;
  int		index;

  index = get_stx_index(data->syntax, ops->operator);
  result = calculs[index].check_and_allocate(&(ops->a), &(ops->b));
  calculs[index].operate(ops->a, ops->b, result, data->base);
  free_number(ops->a, 1);
  free_number(ops->b, 1);
  return (result);
}
