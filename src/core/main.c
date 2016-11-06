/*
** main.c for bistromatique in /home/romain.pillot/github/bistromatique/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:02:31 2016 romain pillot
** Last update Sun Nov  6 17:51:29 2016 Antonin Rapini
*/

#include "main.h"
#include "utils.h"
#include "syntax_handler.h"
#include "base_handler.h"
#include "data.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **args)
{
  t_data	*data;
  t_operator	syntax[7];

  if (ac != 4)
    return (1);
  data = malloc(sizeof(t_data));
  data->syntax = syntax;
  if (!build_syntax(args[2], syntax))
    {
      my_putstr(SYNTAX_ERROR_MSG);
      exit(84);
    }
  if (!(data->base = build_base(&(args[1]))))
    {
      my_putstr(SYNTAX_ERROR_MSG);
      exit(84);
    }
  if (!valid_data(args[2], data->base->charset))
    {
      my_putstr(SYNTAX_ERROR_MSG);
      exit(84);
    }
  free_all(data);
  return (0);
}

static void	free_all(t_data *data)
{
  free(data->base);
  free(data);
}

static char	valid_data(char *a, char *b)
{
  int		a_index;
  int		b_index;

  a_index = 0;
  while(a[a_index++])
    {
      b_index = 0;
      while (b[b_index++])
	if (a[a_index - 1] == b[b_index - 1])
	  return (0);
    }
  return (1);
}

static char	*read_algebraic(int size)
{
  int	len;
  char	*data;

  data = malloc(sizeof(char) * (size + 1));
  len = read(0, data, size);
  data[len] = '\0';
  return (data);
}
