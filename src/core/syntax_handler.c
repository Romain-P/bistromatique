/*
1;4600;0c** data_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 09:27:59 2016 romain pillot
** Last update Sun Nov  6 07:56:30 2016 romain pillot
*/

#include "constants.h"
#include "utils.h"
#include "syntax_handler.h"

char	get_stx_index(char *charset, char op)
{
  int	index;

  index = 0;
  while (op != charset[index++]);
  return (index - 3);
}

char		build_syntax(char *charset, t_operator **syntax)
{
  int		index;
  char		tmp;

  index = 0;
  tmp = 0;
  while (charset[index++])
    {
      if (index > 7 || (tmp && (tmp == charset[index - 1])))
	return (0);
      tmp = charset[index - 1];
      (*syntax)[index - 1].get = tmp;
      (*syntax)[index - 1].lvl = index < 3 ? 0 : index < 5 ? 1 : 2;
    }
  return (index == 7);
}
