/*
** node.c for  in /home/romain.pillot/github/bistromatique/src/struct
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Nov  5 01:23:34 2016 romain pillot
** Last update Sun Nov  6 09:16:47 2016 romain pillot
*/

#include "node.h"

t_node		create_node(t_node *parent)
{
  t_node	*node;

  node = malloc(sizeof(t_node));
  node->operator = 0;
  node->number = 0;
  node->left = 0;
  node->right = 0;
  node->parrent = parent;
  return (node);
}

static void	check_syntax(t_node *current)
{
  
}

void            resolve_node(t_node *current,
			     t_calculs *calculs,
			     t_data *data,
			     t_operator *append)
{
  t_operand     *ops;
  t_number      *result;

  if (current->number)
    return;
  check_syntax(current);
  ops = malloc(sizeof(t_operand));
  ops->a = current->left->number;
  ops->operator = current->operator->get;
  ops->b = current->right->number;
  result = calculate(ops, calculs, data);
  if (!append)
    {
      current->number = result;
      current->operator = 0;
      free(current->left);
      free(current->right);
      return;
    }
  current->left->number = result;
  current->operator = append;
  free(current->right);
}
