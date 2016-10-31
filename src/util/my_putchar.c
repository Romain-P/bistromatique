/*
** my_putchar.c for  in /home/romain.pillot/github/bistromatique
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:39:20 2016 romain pillot
** Last update Fri Oct 28 01:50:22 2016 romain pillot
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
