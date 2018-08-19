/*
** my_putchar.c for emacs in /home/Olivier/CPool_Day10/lib/my
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Mon Oct 17 09:10:34 2016 Olivier Telouk
** Last update Sat May 27 16:51:52 2017 Thery Fouchter
*/

#include "raytracer.h"

void	my_putchar(char c)
{
  int	return_value;

  return_value = write(1, &c, 1);
  return_value = return_value;
}
