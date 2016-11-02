/*
** data_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 09:27:59 2016 romain pillot
** Last update Wed Nov  2 17:16:15 2016 romain pillot
*/

#include "constants.h"
#include "utils.h"

char	get_stx_index(char *charset, char op)
{
  int	index;

  index = 0;
  while (op != charset[index++]);
  return (index - 3);
}

char	build_syntax(char *charset)
{
  int	index;
  char	tmp;

  index = 0;
  tmp = 0;
  while (charset[index++])
    {
      if (tmp && (tmp == charset[index - 1]))
	return (0);
      tmp = charset[index - 1];
    }
  return (index == 7);
}
