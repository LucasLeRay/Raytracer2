/*
** my_getnbr.c for emacs in /home/Olivier/CPool_Day10/lib/my
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Mon Oct 17 15:49:13 2016 Olivier Telouk
** Last update Sat May 27 16:51:48 2017 Thery Fouchter
*/

#include "raytracer.h"

int	calc_stock(int a, char *str, int c)
{
  int	stock;

  stock = 0;
  while (str[a] >= '0' && str[a] <= '9')
    {
      stock = stock + ((str[a] - 48) * c);
      c = c * 10;
      a = a - 1;
    }
  return (stock);
}

int	my_getnbr(char *str)
{
  int	a;
  int	b;
  int	stock;
  int	c;

  c = 1;
  a = 0;
  b = 0;
  if (str[a] == '-')
    {
      b = 1;
      a = a + 1;
    }
  while (str[a] >= '0' && str[a] <= '9')
    a = a + 1;
  a = a - 1;
  stock = calc_stock(a, str, c);
  if (b == 1)
    stock = -stock;
  return (stock);
}
