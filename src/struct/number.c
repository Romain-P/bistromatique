/*
** number.c for  in /home/romain.pillot/github/bistromatique/src/handlers
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Oct 31 12:45:53 2016 romain pillot
** Last update Sat Nov  5 01:55:53 2016 romain pillot
*/

#include <stdlib.h>
#include "utils.h"

t_number	*create_number(char **a, int size, char sign)
{
  t_number	*number;

  number = malloc(sizeof(t_number));
  number->get = *a;
  number->size = size;
  number->sign = sign;
  return (number);
}

t_number        *create_result(int size, int sign)
{
  t_number      *result;

  result = malloc(sizeof(t_number));
  result->sign = sign;
  result->size = size;
  result->get = malloc(sizeof(char) * (size + 1));
  return (result);
}

void    fill_result(char zero, t_number *result)
{
  int   index;

  index = 0;
  while (index < result->size)
    {
      result->get[index] = zero;
      index = index + 1;
    }
  result->get[index] = '\0';
}

char	*free_number(t_number *number, char free_get)
{
  char	*cache;

  if (free_get)
    {
      free(number->get);
      cache = 0;
    }
  else
    cache = number->get;
  free(number);
  return (cache);
}
