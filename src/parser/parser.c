/*
** parser.c for  in /home/romain.pillot/github/bistromatique/src/parser
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov  3 14:35:03 2016 romain pillot
** Last update Sat Nov  5 01:01:43 2016 romain pillot
*/

#include "data.h"
#include "constants.h"

void	parse(char *str, t_data *data)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == data->syntax[BRACKET_OPEN])
	{
	  
	}
      i++;
    }
}
