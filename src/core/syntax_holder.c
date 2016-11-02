/*
** data_holder.c for  in /home/romain.pillot/github/bistromatique/src/core
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 09:27:59 2016 romain pillot
** Last update Wed Nov  2 01:40:58 2016 romain pillot
*/

#include "constants.h"
#include "utils.h"

static char	*private_syntax(char *charset)
{
  static char	stx[7];

  if (charset && *charset)
    {
      stx[BRACKET_OPEN] = charset[0];
      stx[BRACKET_CLOSE] = charset[1];
      stx[OPS_ADD] = charset[2];
      stx[OPS_SUB] = charset[3];
      stx[OPS_MUL] = charset[4];
      stx[OPS_DIV] = charset[5];
      stx[OPS_MOD] = charset[6];
    }
  return (stx);
}

char	get_stx_index(char op)
{
  int	index;
  char	*charset;

  charset = private_syntax(0);
  index = 0;
  while (op != charset[index++]);
  return (index - 1);
}

char	*get_syntax()
{
  return (private_syntax(0));
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
  if (index != 7)
    return (0);
  private_syntax(charset);
  return (1);
}
