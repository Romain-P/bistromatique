/*
** my_getnbr.c for bistromatique in /home/raphael.goulmot/rendu/bistromatique/src/util
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sun Nov  6 11:42:10 2016 Raphaël Goulmot
** Last update Sun Nov  6 18:21:29 2016 Antonin Rapini
*/

#include "utils.h"
#include "constants.h"

int	my_getnbr(char *str)
{
  int	power;
  int	value;

  power = 1;
  value = 1;
  if (*str == '-')
      my_putstr_err(ERROR_MSG);
  while (str[value++])
    power *= 10;
  value = 0;
  while (*(str++))
    {
      value += (*(str - 1) - 48) * power;
      power /= 10;
    }
  return (value);
}
