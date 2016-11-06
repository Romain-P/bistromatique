/*
** parser.c for  in /home/romain.pillot/github/bistromatique/src/parser
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov  3 14:35:03 2016 romain pillot
** Last update Sun Nov  6 13:13:26 2016 romain pillot
*/

#include "data.h"
#include "constants.h"
#include "node.h"
#include "calculator.h"
#include "util.h"

void		on_syntax(t_operator *op,
			  t_node **current,
			  t_data *data,
			  t_calcul *calculs)
{
  t_node	**node;
  t_node	*tmp;

  if (op->get == data->syntax[BRACKET_OPEN])
    {
      tmp = create_node(*current);
      tmp->operator = op;
      (!((*current)->left) ? (*current)->left : (*current)->right) = tmp;
      *current = tmp;
      tmp = create_node(*current);
      (*current)->left = tmp;
      *current = tmp;
    }
  else if (op->get == data->syntax[BRACKET_CLOSE])
    {
      while (*current && (*current)->operator->lvl != 0)
	{
	  resolve_node(current, calculs, data, 0);
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
      (*current)->left->number = current->number;
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

static void build_functions(t_calcul **calculs)
{
  calculs[0] = {&addition, &create_addition_result};
  calculs[1] = {&multiplication, &create_multiplication_result};
  calculs[2] = {&division, &create_division_result};
  calculs[3] = {&modulo, &create_modulo_result};
}

void		parse(char *str, t_data *data)
{
  t_calcul	calculs[4];
  int		i;
  int		j;
  int		ops;
  char		sign;
  t_node	*current;

  i = 0;
  j = 0;
  sign = 1;
  operator = 0;
  while (str[i])
    {
      ops = 0;
      while (ops++ <= 7)
	if (data->syntax[ops - 1] == str[i])
	  on_syntax(&(data->syntax[ops - 1]), &current, data, calculs);
      j = i;
      i++;
    }
}
