/*
** base_holder.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 11:00:06 2016 romain pillot
** Last update Wed Nov  2 01:35:30 2016 romain pillot
*/

#ifndef BASE_HOLDER_
# define BASE_HOLDER_

typedef struct	s_base
{
  int		get;
  char		*charset;
}		t_base;

t_base	*get_base();
int     get_decimal(char c);
char	build_base(char **charset);

#endif /** !BASE_HOLDER_ **/
