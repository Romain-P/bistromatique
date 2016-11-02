/*
** operands.c for  in /home/romain.pillot/github/bistromatique/src/struct
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Nov  2 20:34:41 2016 romain pillot
** Last update Wed Nov  2 20:36:41 2016 romain pillot
*/

#include "calculs.h"

t_operands	*create_operands(t_number **a, t_number **b)
{
  t_operands	*operands;

  operands = malloc(sizeof(t_operands));
  operands->a = *a;
  operands->b = *b;
  return (operands);
}
