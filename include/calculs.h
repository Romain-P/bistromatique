/*
** calculs.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 16:38:27 2016 romain pillot
** Last update Sun Nov  6 16:06:42 2016 romain pillot
*/

#ifndef CALCULS_H_
# define CALCULS_H_

# include "data.h"
# include "number.h"
# include "base_handler.h"

typedef struct	s_operands
{
  t_number	*a;
  t_number	*b;
  char		operator;
}		t_operands;

t_operands	*create_operands(t_number **a, t_number **b);

typedef struct	s_calcul
{
  void		(*operate)(t_number *, t_number *, t_number *, t_base *);
  t_number	*(*check_and_allocate)(t_number **, t_number **, t_base *);
}		t_calcul;

void		addition(t_number *a, t_number *b, t_number *result, t_base *base);
void		division(t_number *a, t_number *b, t_number *result, t_base *base);
void		multiplication(t_number *a, t_number *b, t_number *result, t_base *base);
void		modulo(t_number *a, t_number *b, t_number *result, t_base *base);

t_number	*create_addition_result(t_number **a, t_number **b, t_base *base);
t_number	*create_multiplication_result(t_number **a, t_number **b, t_base *base);
t_number	*create_division_result(t_number **a, t_number **b, t_base *base);
t_number	*create_modulo_result(t_number **a, t_number **b, t_base *base);

#endif /** !CALCULS_ **/
