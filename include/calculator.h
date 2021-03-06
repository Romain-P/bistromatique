/*
** calculator.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Nov  2 02:12:30 2016 romain pillot
** Last update Sun Nov  6 17:30:36 2016 romain pillot
*/

#ifndef CALCULATOR_H_
# define CALCULATOR_H_

# include "number.h"
# include "data.h"

t_number	*calculate(t_operands *ops, t_calcul calcs[], t_data *data);
void		parse(char *expr, t_data *data);

#endif /** !CALCULATOR_H_ **/
