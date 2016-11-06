/*
** parser.c for  in /home/romain.pillot/github/bistromatique/src/parser
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov  3 14:35:03 2016 romain pillot
** Last update Sun Nov  6 08:01:25 2016 romain pillot
*/

#include "data.h"
#include "constants.h"
#include "node.h"
#include "calculator.h"
#include "util.h"

void		on_syntax(t_operator *op, t_node **current, t_data *data)
{
  t_node	**node;
  t_node	*tmp;

  if (op->get == data->syntax[BRACKET_OPEN])
    {
      tmp = create_node(*current);
      tmp->operator = op;
      (!((*current)->left) ? (*current)->right : (*current)->left) = tmp;
      *current = tmp;
    }
  else if (op->get == data->syntax[BRACKET_CLOSE])
    {
      while (*current && (*current)->operator.lvl != 0)
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
      
    }
  else if (op->lvl <= (*current)->operator.lvl)
    {
      resolve_node(*current, calculs, data, op);
    }
}

void		parse(char *str, t_data *data)
{
  int		i;
  int		j;
  int		ops;
  char		sign;
  char		operator;
  t_node	*tree;

  i = 0;
  j = 0;
  sign = 1;
  operator = 0;
  while (str[i])
    {
      ops = 0;
      while (ops++ <= 7)
	if (data->syntax[ops - 1] == str[i])
	  on_syntax(&(data->syntax[ops - 1]), &tree, data);	
      j = i;
      i++;
    }
}
