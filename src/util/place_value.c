/*
** operations.c for infin_add in /home/antonin.rapini/CPool_infinadd
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Oct 25 16:00:17 2016 Antonin Rapini
** Last update Fri Nov  4 13:36:57 2016 Antonin Rapini
*/

#include "mynumber.h"
#include <stdlib.h>
#include "my.h"

void	place_value(int holder, int nbrf_index, t_number *nbrf)
{
  int	retenue;

  retenue = holder / 10;
  nbrf->get[nbrf_index] = (holder % 10) + '0';
  while (nbrf_index > 0 && nbrf->get[--nbrf_index] - 48 + retenue > 9)
    {
      nbrf->get[nbrf_index] = ((nbrf->get[nbrf_index] - 48) + retenue - 10) + 48;
      retenue = 1;
    }
  nbrf->get[nbrf_index] = nbrf->get[nbrf_index] + retenue;
}
