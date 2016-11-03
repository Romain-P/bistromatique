/*
** main.c for bistromatique in /home/romain.pillot/github/bistromatique/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:02:31 2016 romain pillot
** Last update Thu Nov  3 14:26:41 2016 romain pillot
*/

#include "main.h"
#include "utils.h"
#include "syntax_handler.h"
#include "base_handler.h"
#include "data.h"
#include "stdlib.h"

int		main(int ac, char **args)
{
  t_data	*data;

  if (ac != 4)
    return (1);
  data = malloc(sizeof(data));
  if (!build_syntax((data->syntax = args[2])))
    return (1);
  if (!(data->base = build_base(&(args[1]))))
    return (1);
  if (!valid_data(data->syntax, data->base->charset))
    return (1);
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
  while (*a && *b)
    if (*(a++) == *(b++))
      return (0);
  return (1);
}
