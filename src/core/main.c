/*
** main.c for bistromatique in /home/romain.pillot/github/bistromatique/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:02:31 2016 romain pillot
** Last update Wed Nov  2 16:04:52 2016 Raphaël Goulmot
*/

#include "main.h"
#include "utils.h"
#include "syntax_holder.h"
#include "base_holder.h"

int	main(int ac, char **args)
{
  if (ac != 4)
    return (1);
  if (!build_syntax(args[2]))
    return (1);
  if (!build_base(&(args[1])))
    return (1);
  if (!valid_attributes(get_syntax(), get_base()))
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

static char	*read_algebraic(char *str)
{
  int	len;

  len = read(0, str, SIZE_READ);
  str[len] = '\0';
  return (str);
}
