/*
** main.c for bistromatique in /home/romain.pillot/github/bistromatique/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:02:31 2016 romain pillot
** Last update Sun Nov  6 18:08:34 2016 Raphaël Goulmot
*/

#include "main.h"
#include "utils.h"
#include "syntax_handler.h"
#include "base_handler.h"
#include "data.h"
#include "constants.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **args)
{
  t_data	*data;
  t_operator	syntax[7];

  if (ac != 4)
    {
      my_putstr_err("Usage: ");
      my_putstr_err(args[0]);
      my_putstr_err(" base ops \"()+-*/%\" exp_len \n");
    }
  data = malloc(sizeof(t_data));
  data->syntax = syntax;
  if (!build_syntax(args[2], syntax)
      || !(data->base = build_base(&(args[1])))
      || !valid_data(args[2], data->base->charset))
    my_putstr_err(SYNTAX_ERROR_MSG);
  my_printf("Pipe : %s", read_algebraic(my_getnbr(args[3])));
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
