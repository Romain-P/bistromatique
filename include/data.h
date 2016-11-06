/*
** data.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Nov  2 17:34:33 2016 romain pillot
** Last update Sat Nov  5 03:49:27 2016 romain pillot
*/

#ifndef DATA_H_
# define DATA_H_

#include "calculs.h"
#include "base_handler.h"
#include "syntax_handler.h"

typedef struct	s_data
{
  t_base	*base;
  t_operator	*syntax;
}		t_data;

#endif /** !DATA_H_ **/
