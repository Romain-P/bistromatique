/*
** my_putstr.c for  in /home/romain.pillot/github/bistromatique/src/utils
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:35:41 2016 romain pillot
** Last update Fri Oct 28 02:27:57 2016 romain pillot
*/

#include <unistd.h>
#include "utils.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
