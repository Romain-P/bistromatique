/*
** data.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Nov  2 17:34:33 2016 romain pillot
** Last update Thu Nov  3 14:03:32 2016 romain pillot
*/

#ifndef DATA_H_
# define DATA_H_

#include "calculs.h"
#include "base_handler.h"

typedef struct	s_data
{
  t_base	*base;
  char		*syntax;
}		t_data;

t_data		*create_data(t_base base, char *syntax);

#endif /** !DATA_H_ **/
