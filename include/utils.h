/*
** utils.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:28:02 2016 romain pillot
** Last update Sun Nov  6 14:49:37 2016 Raphaël Goulmot
*/

#ifndef UTILS_H_
# define UTILS_H_

# include "number.h"

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
void    my_printf(char *str, ...);
void    my_put_nbr(int nbr);
char	is_greater(t_number *a, t_number *b, t_base *base);
void    place_value(int holder, int nbrf_index, t_number *nbrf, t_base *base);
void    copy_smaller_nbr(char zero, char *a_temp, t_number *a);
char    is_greater(t_number *a, t_number *b, t_base *base);
int     is_zero(char zero, char *nbr);

#endif /** !UTILS_H_ **/
