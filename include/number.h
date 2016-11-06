/*
** number.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Oct 31 14:14:40 2016 romain pillot
** Last update Sun Nov  6 20:55:02 2016 romain pillot
*/

#ifndef NUMBER_H_
# define NUMBER_H_

typedef struct	s_number
{
  char		malloced;
  char		*get;
  int		size;
  char		sign;
}		t_number;

t_number	*create_number(char **a, int size, char sign);
char		*free_number(t_number *nbr, char free_get);
t_number        *create_result(int size, int sign);
void		fill_result(char zero, t_number *result);
void		init_number(t_number *number);

#endif /** !NUMBER_H_ **/
