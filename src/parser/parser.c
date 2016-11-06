/*
** parser.c for  in /home/romain.pillot/github/bistromatique/src/parser
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov  3 14:35:03 2016 romain pillot
** Last update Sun Nov  6 22:30:55 2016 romain pillot
*/

#include "data.h"
#include "constants.h"
#include "node.h"
#include "calculator.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

void		on_syntax(t_operator *op,
			  t_node **current,
			  t_data *data,
			  t_calcul calculs[])
{
  t_node	*tmp;

  if (op->get == data->syntax[BRACKET_OPEN].get)
    {
      tmp = create_bracket_node(*current, op);
      if (!((*current)->left))
	(*current)->left = tmp;
      else
	(*current)->right = tmp;
      *current = tmp->left;
    }
  else if (op->get == data->syntax[BRACKET_CLOSE].get)
    {
      while (*current && (*current)->operator->lvl != 0)
	{
	  resolve_node(*current, calculs, data, 0);
	  *current = (*current)->parent;
	}
      if (!(*current))
	  my_putstr_err("Syntax error\n");
      (*current)->number = (*current)->left->number;
      (*current)->operator = 0;
      free((*current)->left);
      *current = (*current)->parent;
    }
  else if (!((*current)->operator))
    {
      (*current)->operator = op;
      if (!((*current)->number) || !((*current)->number->get))
	my_putstr_err(SYNTAX_ERROR_MSG);
      (*current)->left = create_node(*current, (*current)->number);
      (*current)->number = 0;
    }
  else if (op->lvl > (*current)->operator->lvl)
    {
      (*current) = (*current)->right;
      tmp = create_node(*current, (*current)->number);
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

void		insert_number(t_node *current, char *str, int size, char sign)
{
  t_number	*number;

  if (!(current->operator))
    number = current->number;
  else if (!(current->left) && !(current->left->number->size > 0))
    {
      if (!(current->left))
	current->left = create_node(current, 0);
      number = current->left->number;
    }
  else if (!(current->right) && !(current->right->number->size > 0))
    {
      if (!(current->right))
	current->right = create_node(current, 0);
      number = current->right->number;
    }
  number->get = str;
  number->size = size;
  if (sign > 0 || sign < 0)
    number->sign *= sign;
}

static char	free_place(t_node *current)
{
  return ((!(current->operator) && !(current->number->size > 0))
	  || !(current->number->size > 0));
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
  current = create_node(0, 0);
  i = 0;
  j = 0;
  sign = 1;
  if (j++ && sign++) {}
  while (str[i])
    {
      if (i == 0)
	while (str[i] && (str[i] == data->syntax[OPS_SUB].get || str[i] == data->syntax[OPS_ADD].get))
	  if (str[i++] == data->syntax[OPS_SUB].get)
	    current->number->sign *= -1;
      if (!(str[i]))
	my_putstr_err(SYNTAX_ERROR_MSG);
      ops = 0;
      while (ops++ < 7)
	if (data->syntax[ops - 1].get == str[i])
	  {
	    if (!free_place(current))
	      {
		on_syntax(&(data->syntax[ops - 1]), &current, data, calculs);
		ops = 8;
	      }
	    else
	      {
		if (str[i] == data->syntax[OPS_SUB].get || str[i] == data->syntax[OPS_ADD].get)
		  {
		    if (str[i] == data->syntax[OPS_SUB].get)
		      {
			insert_number(current, 0, 0, -1);
			ops = 8;
		      }
		  }
		else
		  my_putstr_err(SYNTAX_ERROR_MSG);
	      }
	  }
      if (ops < 8)
	{
	  j = i;
	  while (str[j] && get_safe_decimal(data->base, str[j]) != -1)
	    j++;
	  insert_number(current, str + i, j - i, 0);
	}
      i++;
    }
}
