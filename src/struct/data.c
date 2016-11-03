/*
** data.c for  in /home/romain.pillot/github/bistromatique/src/struct
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov  3 13:30:57 2016 romain pillot
** Last update Thu Nov  3 13:46:19 2016 romain pillot
*/

#include "base_handler.h"
#include "data.h"

t_data		*create_data(t_base **base, char **syntax)
{
  t_data	*data;

  data = malloc(sizeof(t_data));
  data->base = *base;
  data->syntax = *syntax;
}
