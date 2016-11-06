/*
** main.c for bistromatique in /home/romain.pillot/github/bistromatique/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:02:31 2016 romain pillot
** Last update Sun Nov  6 22:31:45 2016 romain pillot
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
#include "calculator.h"

int		main(int ac, char **args)
{
  t_data	*data;
  t_operator	syntax[7];

  if (ac != 4)
    {
      my_putstr("Usage: ");
      my_putstr(args[0]);
      my_putstr(" base ops \"()+-*/%\" exp_len\n");
      exit(84);
    }
  data = malloc(sizeof(t_data));
  if (data == NULL)
    my_putstr_err(ERROR_MSG);
  data->syntax = syntax;
  if (!build_syntax(args[2], syntax)
      || !(data->base = build_base(&(args[1])))
      || !valid_data(args[2], data->base->charset))
    my_putstr_err(SYNTAX_ERROR_MSG);
  parse(read_algebraic(my_getnbr(args[3])), data);
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
  while (a[a_index++])
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
  int		len;
  char		*data;

  data = malloc(sizeof(char) * (size + 1));
  if (data == NULL)
    my_putstr_err(ERROR_MSG);
  len = read(0, data, size);
  data[len] = '\0';
  return (data);
}
