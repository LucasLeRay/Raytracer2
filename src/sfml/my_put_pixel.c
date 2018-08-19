/*
** my_put_pixel.c for  in /home/Thery/Desktop/raytracer2/src
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 13:44:28 2017 Thery Fouchter
** Last update Wed Mar 22 13:44:46 2017 Thery Fouchter
*/

#include "raytracer.h"

void	my_put_pixel(t_my_framebuffer *framebuffer,
		     int x,
		     int y,
		     sfColor color)
{
  int	pos;

  if (x >= 0 && x < framebuffer->width && y >= 0 && y < framebuffer->height)
    {
      pos = (((framebuffer->width * y) + x) * 4);
      framebuffer->pixels[pos] = color.r;
      framebuffer->pixels[pos + 1] = color.g;
      framebuffer->pixels[pos + 2] = color.b;
      framebuffer->pixels[pos + 3] = color.a;
    }
}
