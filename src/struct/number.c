/*
** number.c for  in /home/romain.pillot/github/bistromatique/src/handlers
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Oct 31 12:45:53 2016 romain pillot
** Last update Sun Nov  6 20:59:30 2016 romain pillot
*/

#include <stdlib.h>
#include "number.h"
#include "constants.h"
#include "utils.h"

t_number	*create_number(char **a, int size, char sign)
{
  t_number	*number;

  number = malloc(sizeof(t_number));
  if (number == NULL)
    my_putstr_err(ERROR_MSG);
  number->get = *a;
  number->size = size;
  number->sign = sign;
  return (number);
}

t_number	*create_result(int size, int sign)
{
  t_number	*result;

  result = malloc(sizeof(t_number));
  if (result == NULL)
    my_putstr_err(ERROR_MSG);
  result->sign = sign;
  result->size = size;
  result->get = malloc(sizeof(char) * (size + 1));
  if (result->get == NULL)
    my_putstr_err(ERROR_MSG);
  return (result);
}

void	fill_result(char zero, t_number *result)
{
  int	index;

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

  if (free_get && number->malloced > 0)
    {
      free(number->get);
      cache = 0;
    }
  else
    cache = number->get;
  free(number);
  return (cache);
}

void	init_number(t_number *number)
{
  number->sign = 1;
  if (number->malloced)
    free(number->get);
  number->size = 0;
}
