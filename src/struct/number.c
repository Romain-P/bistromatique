/*
** number.c for  in /home/romain.pillot/github/bistromatique/src/handlers
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Oct 31 12:45:53 2016 romain pillot
** Last update Tue Nov  1 14:14:14 2016 romain pillot
*/

#include <stdlib.h>
#include "utils.h"

t_number	*create_number(char **a, char *sign)
{
  t_number	*number;

  number = malloc(sizeof(t_number));
  number->get = *a;
  number->size = my_strlen(*a);
  number->sign = *sign;
  return (number);
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
