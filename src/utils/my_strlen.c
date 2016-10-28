/*
** my_strlen.c for  in /home/romain.pillot/github/bistromatique/src/utils
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct 28 01:32:50 2016 romain pillot
** Last update Fri Oct 28 04:55:07 2016 romain pillot
*/

int	my_strlen(char *str)
{
  int	len;

  len = 0;
  while (str[len] && ++len);
  return (len);
}
