/*
** operations.c for infin_add in /home/antonin.rapini/CPool_infinadd
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Oct 25 16:00:17 2016 Antonin Rapini
** Last update Sun Nov  6 19:51:46 2016 Antonin Rapini
*/

#include "number.h"
#include <stdlib.h>
#include "utils.h"

void    copy_smaller_nbr(char zero, char *a_temp, t_number *a)
{
  int   ati;
  int   ai;

  ati = 0;
  ai = 0;
  while (a_temp[ati] == zero && a_temp[ati + 1])
    ati++;
  while (a_temp[ati])
    {
      a->get[ai] = a_temp[ati];
      ai++;
      ati++;
    }
  a->get[ai] = '\0';
  a->size = my_strlen(a->get);
}
