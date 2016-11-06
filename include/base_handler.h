/*
** base_holder.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 11:00:06 2016 romain pillot
** Last update Sun Nov  6 22:22:02 2016 romain pillot
*/

#ifndef BASE_HANDLER_H_
# define BASE_HANDLER_H_

typedef struct	s_base
{
  int		size;
  char		*charset;
}		t_base;

int     get_decimal(t_base *base, char c);
int	get_safe_decimal(t_base *base, char c);
char	get_char(t_base *base, int decimal);
t_base	*build_base(char **charset);

#endif /** !BASE_HANDLER_H_ **/
