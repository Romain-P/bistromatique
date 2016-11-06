/*
** my_putstr.c for  in /home/romain.pillot/github/bistromatique/src/utils
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:35:41 2016 romain pillot
** Last update Sun Nov  6 18:10:58 2016 Raphaël Goulmot
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

void	my_putstr_err(char *str)
{
  write(2, str, my_strlen(str));
  exit(84);
}
