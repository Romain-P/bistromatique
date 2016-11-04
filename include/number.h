/*
** number.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Oct 31 14:14:40 2016 romain pillot
** Last update Fri Nov  4 19:40:25 2016 Antonin Rapini
*/

#ifndef NUMBER_
# define NUMBER_

typedef struct	s_number
{
  char		*get;
  int		size;
  char		sign;
}		t_number;

t_number	*create_number(char **a, char *sign);
char		*free_number(t_number *nbr, char free_get);
t_number        *create_result(int size, int sign);
void		fill_result(char zero, t_number *result);

#endif /** !NUMBER_ **/
