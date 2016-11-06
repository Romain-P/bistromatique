/*
** syntax_holder.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 09:47:45 2016 romain pillot
** Last update Sun Nov  6 21:45:51 2016 Antonin Rapini
*/

#ifndef SYNTAX_HANDLER_H_
# define SYNTAX_HANDLER_H_

typedef struct	s_operator
{
  char	get;
  char	lvl;
}		t_operator;

char		get_stx_index(t_operator charset[], char operator);
char		build_syntax(char *charset, t_operator ops[]);

#endif /** !SYNTAX_HANDLER_H_ **/
