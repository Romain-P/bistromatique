/*
** data_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 09:27:59 2016 romain pillot
** Last update Wed Nov  2 00:17:40 2016 romain pillot
*/

#include "constants.h"
#include "utils.h"

static char	*private_syntax(char *str)
{
  static char	stx[7];

  if (str && *str) 
    {
      stx[BRACKET_OPEN] = str[0];
      stx[BRACKET_CLOSE] = str[1];
      stx[OPS_ADD] = str[2];
      stx[OPS_SUB] = str[3];
      stx[OPS_MUL] = str[4];
      stx[OPS_DIV] = str[5];
      stx[OPS_MOD] = str[6];
    }
  return (stx);
}

char	get_stx_index(char op)
{
  int	index;
  
  index = 0;
  while (op != private_syntax(0)[index++]);
  return (index - 1);
}

char	*get_syntax()
{
  return (private_syntax(0));
}

char	build_syntax(char *str)
{
  int	index;
  char	tmp;

  index = 0;
  tmp = 0;
  while (str[index++])
    {
      if (tmp && (tmp == str[index - 1]))
	return (0);
      tmp = str[index - 1];
    }
  if (index != 7)
    return (0);
  private_syntax(str);
  return (1);
}
