/*
** data_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 09:27:59 2016 romain pillot
** Last update Sun Nov  6 17:31:07 2016 Antonin Rapini
*/

#include "constants.h"
#include "utils.h"
#include "syntax_handler.h"

char	get_stx_index(t_operator ops[], char op)
{
  int	index;

  index = 0;
  while (op != ops[index++].get);
  return (index - 3);
}

char		build_syntax(char *charset, t_operator syntax[])
{
  int		index;
  int		index2;

  index = 0;
  while (charset[index++])
    {
      index2 = index;
      while (charset[index2++])
	if (charset[index - 1] == charset[index2 - 1])
	    return (0);
      if (index > 7)
	return (0);
      syntax[index - 1].get = charset[index - 1];
      syntax[index - 1].lvl = index < 3 ? 0 : index < 5 ? 1 : 2;
    }
  return (index - 1 == 7);
}
