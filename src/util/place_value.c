/*
** operations.c for infin_add in /home/antonin.rapini/CPool_infinadd
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Oct 25 16:00:17 2016 Antonin Rapini
** Last update Sun Nov  6 21:11:09 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "number.h"
#include "base_handler.h"

void	place_value(int holder, int nbrf_index, t_number *nbrf, t_base *base)
{
  int	retenue;

  retenue = holder / base->size;
  nbrf->get[nbrf_index] = get_char(base, holder % base->size);
  while (nbrf_index > 0 && get_decimal(base, nbrf->get[--nbrf_index]) + retenue
	 > base->size - 1)
    {
      nbrf->get[nbrf_index] =
	get_char(base, get_decimal(base, nbrf->get[nbrf_index])
		 + retenue - base->size);
      retenue = 1;
    }
  nbrf->get[nbrf_index] =
    get_char(base, get_decimal(base, nbrf->get[nbrf_index]) + retenue);
}
