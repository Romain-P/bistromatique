/*
** utils.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:28:02 2016 romain pillot
** Last update Sat Nov  5 01:04:13 2016 romain pillot
*/

#ifndef UTILS_H_
# define UTILS_H_

# include "number.h"

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
char	is_greater(t_number *a, t_number *b);
void    place_value(int holder, int nbrf_index, t_number *nbrf);
void    copy_smaller_nbr(char *a_temp, t_number *a);
char    is_greater(t_number *a, t_number *b);
int     is_zero(char *nbr);

#endif /** !UTILS_H_ **/
