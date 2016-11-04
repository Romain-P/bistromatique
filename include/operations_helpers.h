/*
** division.h for bistromatique in /home/raphael.goulmot/rendu/bistromatique/include
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon Oct 31 17:24:45 2016 Raphaël Goulmot
** Last update Fri Nov  4 19:40:18 2016 Antonin Rapini
*/

#ifndef OPERATIONS_HELPERS_H
# define OPERATIONS_HELPERS_H

#include "number.h"

void	place_value(int holder, int nbrf_index, t_number *nbrf);
void    copy_smaller_nbr(char *a_temp, t_number *a);
char    is_greater(t_number *a, t_number *b);
int     is_zero(char *nbr);

#endif /* !OPERATIONS_HELPERS */