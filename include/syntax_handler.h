/*
** syntax_holder.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 09:47:45 2016 romain pillot
** Last update Sun Nov  6 07:52:32 2016 romain pillot
*/

#ifndef SYNTAX_HANDLER_H_
# define SYNTAX_HANDLER_H_

typedef struct	s_operator
{
  char	get;
  char	lvl;
}		t_operator;

char		get_stx_index(char *charset, char operator);
t_operator	*build_syntax(char *charset);

#endif /** SYNTAX_HANDLER_H_ **/
