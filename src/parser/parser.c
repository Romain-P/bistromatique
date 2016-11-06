/*
** parser.c for  in /home/romain.pillot/github/bistromatique/src/parser
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov  3 14:35:03 2016 romain pillot
** Last update Sun Nov  6 15:50:42 2016 romain pillot
*/

#include "data.h"
#include "constants.h"
#include "node.h"
#include "calculator.h"
#include "utils.h"
#include <stdlib.h>

void		on_syntax(t_operator *op,
			  t_node **current,
			  t_data *data,
			  t_calcul calculs[])
{
  t_node	*tmp;

  if (op->get == data->syntax[BRACKET_OPEN].get)
    {
      tmp = create_node(*current);
      tmp->operator = op;
      if (!((*current)->left))
	(*current)->left = tmp;
      else
	(*current)->right = tmp;
      *current = tmp;
      tmp = create_node(*current);
      (*current)->left = tmp;
      *current = tmp;
    }
  else if (op->get == data->syntax[BRACKET_CLOSE].get)
    {
      while (*current && (*current)->operator->lvl != 0)
	{
	  resolve_node(*current, calculs, data, 0);
	  *current = (*current)->parent;
	}
      if (!((*current)))
	{
	  my_putstr("Syntax error\n");
	  exit(84);
	}
      (*current)->number = (*current)->left->number;
      (*current)->operator = 0;
      free((*current)->left);
      *current = (*current)->parent;
    }
  else if (!((*current)->operator))
    {
      (*current)->operator = op;
      if (!(*current)->number)
	return;
      (*current)->left = create_node(*current);
      (*current)->left->number = (*current)->number;
      (*current)->number = 0;
    }
  else if (op->lvl > (*current)->operator->lvl)
    {
      (*current) = (*current)->right;
      tmp = create_node(*current);
      tmp->number = (*current)->number;
      (*current)->left = tmp;
      (*current)->operator = op;
      (*current)->number = 0;
    }
  else if (op->lvl <= (*current)->operator->lvl)
    {
      resolve_node(*current, calculs, data, op);
    }
}

static void	build_functions(t_calcul calculs[])
{
  calculs[0].check_and_allocate = &create_addition_result;
  calculs[0].operate = &addition;
  calculs[1].check_and_allocate = &create_multiplication_result;
  calculs[1].operate = &multiplication;
  calculs[2].check_and_allocate = &create_division_result;
  calculs[2].operate = &division;
  calculs[3].check_and_allocate = &create_modulo_result;
  calculs[3].operate = &modulo;
}

void		parse(char *str, t_data *data)
{
  t_calcul	calculs[4];
  int		i;
  int		j;
  int		ops;
  char		sign;
  t_node	*current;

  build_functions(calculs);
  i = 0;
  j = 0;
  sign = 1;
  if (j++ && sign++) {}
  while (str[i])
    {
      ops = 0;
      while (ops++ <= 7)
	if (data->syntax[ops - 1].get == str[i])
	  on_syntax(&(data->syntax[ops - 1]), &current, data, calculs);
      j = i;
      i++;
    }
}
