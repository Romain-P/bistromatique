/*
** my_getnbr.c for bistromatique in /home/raphael.goulmot/rendu/bistromatique/src/util
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sun Nov  6 11:42:10 2016 Raphaël Goulmot
** Last update Sun Nov  6 12:12:39 2016 Raphaël Goulmot
*/

int	my_getnbr(char *str)
{
  int	power;
  char	neg;
  int	value;

  power = 1;
  value = 1;
  neg = *str == '-' ? 1 : 0;
  if (neg)
    str++;
  while (str[value++])
    power *= 10;
  value = 0;
  while (*(str++))
    {
      value += (*(str - 1) - 48) * power;
      power /= 10;
    }
  value *= neg ? -1 : 1;
  return (value);
}
