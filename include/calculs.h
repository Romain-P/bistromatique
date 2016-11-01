/*
** calculs.h for  in /home/romain.pillot/github/bistromatique/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Nov  1 16:38:27 2016 romain pillot
** Last update Tue Nov  1 18:05:43 2016 romain pillot
*/

#ifndef CALCULS_
# define CALCULS_

void		addition(t_number *a, t_number *b, t_number *result);
void		division(t_number *a, t_number *b, t_number *result);
void		multiplication(t_number *a, t_number *b, t_number *result);
void		modulo(t_number *a, t_number *b, t_number *result);

t_number	*create_addition_result(t_number *a, t_number *b);
t_number	*create_multiplication_result(t_number *a, t_number *b);
t_number	*create_division_result(t_number *a, t_number *b);
t_number	*create_modulo_result(t_number *a, t_number *b);

#endif /** !CALCULS_ **/
