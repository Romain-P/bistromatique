/*
** utils.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:28:02 2016 romain pillot
** Last update Sun Nov  6 11:59:41 2016 Antonin Rapini
*/

#ifndef UTILS_H_
# define UTILS_H_

# include "number.h"

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
char	is_greater(t_number *a, t_number *b);
void    place_value(int holder, int nbrf_index, t_number *nbrf, t_base *base);
void    copy_smaller_nbr(char zero, char *a_temp, t_number *a);
char    is_greater(t_number *a, t_number *b, t_base *base);
int     is_zero(char zero, char *nbr);

#endif /** !UTILS_H_ **/
