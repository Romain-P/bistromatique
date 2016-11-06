/*
** operations.c for infin_add in /home/antonin.rapini/CPool_infinadd
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Oct 25 16:00:17 2016 Antonin Rapini
** Last update Sun Nov  6 15:55:55 2016 romain pillot
*/

#include "number.h"
#include <stdlib.h>

int	is_zero(char zero, char *nbr)
{
  while (*nbr)
    {
      if (*nbr != zero)
	return (0);
      nbr++;
    }
  return (1);
}
