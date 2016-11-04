/*
** operations.c for infin_add in /home/antonin.rapini/CPool_infinadd
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Oct 25 16:00:17 2016 Antonin Rapini
** Last update Fri Nov  4 13:38:08 2016 Antonin Rapini
*/

#include "mynumber.h"
#include <stdlib.h>
#include "my.h"

void    copy_smaller_nbr(char *a_temp, t_number *a)
{
  int   ati;
  int   ai;

  ati = 0;
  ai = 0;
  while(a_temp[ati] == '0' && a_temp[ati + 1])
    ati++;
  while(a_temp[ati])
    {
      if(a_temp[ati] > '9' || a_temp[ati] < '0')
	exit(84);
      a->get[ai] = a_temp[ati];
      ai++;
      ati++;
    }
  a->get[ai] = '\0';
  a->size = my_strlen(a->get);
}
