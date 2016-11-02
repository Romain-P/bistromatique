/*
** my_swap.c for  in /home/romain.pillot/github/bistromatique/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Nov  2 21:05:41 2016 romain pillot
** Last update Wed Nov  2 21:16:44 2016 romain pillot
*/

void	swap_pointers(void **a, void **b)
{
  void	*c;

  c = *a;
  *a = *b;
  *b = c;
}
