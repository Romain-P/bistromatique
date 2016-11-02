/*
** main.c for bistromatique in /home/romain.pillot/github/bistromatique/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:02:31 2016 romain pillot
** Last update Wed Nov  2 19:42:47 2016 romain pillot
*/

#include "main.h"
#include "utils.h"
#include "syntax_handler.h"
#include "base_handler.h"

int		main(int ac, char **args)
{
  t_base	*base;
  char		*syntax;
  
  if (ac != 4)
    return (1);
  if (!build_syntax((syntax = args[2])))
    return (1);
  if (!(base = build_base(&(args[1]))))
    return (1);
  if (!valid_attributes(syntax, base->charset))
    return (1);
  return (0);
}

static char	valid_attributes(char *a, char *b)
{
  while (*a && *b)
    if (*(a++) == *(b++))
      return (0);
  return (1);
}
