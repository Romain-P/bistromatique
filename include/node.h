/*
** node.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Nov  5 01:06:42 2016 romain pillot
** Last update Sun Nov  6 08:01:40 2016 romain pillot
*/

#ifndef NODE_H_
# define NODE_H_

# include "number.h"
# include "data.h"

typedef struct	s_node
{
  t_operator	*operator;
  t_number	*value;
  struct s_node	*left;
  struct s_node *right;
  struct s_node *parent;
}		t_node;

t_node	*create_node(t_node *parent);
void	resolve_node(t_node *current, t_calculs *, t_data *, t_operator append);

#endif /** !NODE_H_
