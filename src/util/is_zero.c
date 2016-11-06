/*
** operations.c for infin_add in /home/antonin.rapini/CPool_infinadd
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Oct 25 16:00:17 2016 Antonin Rapini
** Last update Sat Nov  5 20:19:37 2016 Antonin Rapini
*/

#include "number.h"
#include <stdlib.h>
#include "my.h"

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
