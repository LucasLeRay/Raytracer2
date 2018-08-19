/*
** my_put_nbr.c for emacs in /home/Olivier/raytracer2
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Fri May 26 13:23:14 2017 Olivier Telouk
** Last update Sat May 27 16:51:36 2017 Thery Fouchter
*/

#include "raytracer.h"

int	my_put_nbr(int nb)
{
  long	v;
  int	p;

  v = nb;
  if (v < 0)
    {
      my_putchar('-');
      v = v * -1;
    }
  if (v < 10)
    my_putchar(v + 48);
  if (v >= 10)
    {
      p = v % 10;
      v = v / 10;
      my_put_nbr(v);
      my_putchar(p + 48);
    }
  return (0);
}
