/*
** main.c for bistromatique in /home/romain.pillot/github/bistromatique/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:02:31 2016 romain pillot
** Last update Sun Nov  6 16:11:37 2016 romain pillot
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

  printf("hello kitty: %s\n", read_algebraic(my_getnbr(args[3])));
  
  if (ac != 4)
    return (1);
  data = malloc(sizeof(t_data));
  data->syntax = syntax;
  if (!build_syntax(args[2], &syntax))
    {
      printf("pute");
      return (1);
    }
  if (!(data->base = build_base(&(args[1]))))
    {
      printf("antonin");
      return (1);
    }
  if (!valid_data(args[2], data->base->charset))
    {
      printf("raph");
      return (1);
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
  while (*a && *b)
    if (*(a++) == *(b++))
      return (0);
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
