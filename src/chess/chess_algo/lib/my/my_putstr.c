/*
** my_putstr.c for emacs in /home/Olivier/delivery
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Thu Oct  6 15:08:24 2016 Olivier Telouk
** Last update Sat May 27 16:51:31 2017 Thery Fouchter
*/

#include "raytracer.h"

int	my_putstr(char *str)
{
  int	 i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
