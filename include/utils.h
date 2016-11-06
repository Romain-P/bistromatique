/*
** utils.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:28:02 2016 romain pillot
<<<<<<< HEAD
** Last update Sun Nov  6 12:02:38 2016 Raphaël Goulmot
=======
** Last update Thu Nov  3 14:33:51 2016 Raphaël Goulmot
>>>>>>> c4f28da62bab5e22e07804b2e9c049b397fa8842
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
void    my_printf(char *str, ...);
void    my_put_nbr(int nbr);

#endif /** !UTILS_H_ **/
