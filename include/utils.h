/*
** utils.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:28:02 2016 romain pillot
** Last update Thu Nov  3 14:33:51 2016 Raphaël Goulmot
*/

#ifndef UTILS_H_
# define UTILS_H_

# include "number.h"

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
char	is_greater(t_number *a, t_number *b);
void	my_printf(char *str, ...);
void	my_put_nbr(int nbr);

#endif /** !UTILS_H_ **/
