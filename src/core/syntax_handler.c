/*
1;4600;0c** data_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 09:27:59 2016 romain pillot
** Last update Sun Nov  6 10:59:12 2016 Raphaël Goulmot
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
  int		old;

  index = 0;
  old = 0;
  while (charset[old] && index++)
    {
      if (!charset[index - 1])
	{
	  index = 1;
	  old++;
	}
      if (old > 6 || charset[old])
	return (0);
      (*syntax)[index - 1].get = charset[old];
      (*syntax)[index - 1].lvl = index < 3 ? 0 : index < 5 ? 1 : 2;
    }
  return (old == 6);
}
