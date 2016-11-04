/*
** operations.c for infin_add in /home/antonin.rapini/CPool_infinadd
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Oct 25 16:00:17 2016 Antonin Rapini
** Last update Fri Nov  4 13:37:29 2016 Antonin Rapini
*/

#include "mynumber.h"
#include <stdlib.h>
#include "my.h"

int	is_zero(char *nbr)
{
  while (*nbr)
    {
      if (*nbr != '0')
	return (0);
      nbr++;
    }
  return (1);
}
