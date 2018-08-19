/*
** framebuffer.c for  in /home/Thery/Desktop/raytracer2/src
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 13:42:30 2017 Thery Fouchter
** Last update Wed Mar 22 13:42:37 2017 Thery Fouchter
*/

#include "raytracer.h"

t_my_framebuffer	*init_framebuffer(int width, int height)
{
  t_my_framebuffer	*buffer;
  sfUint8		*pixels;
  int			i;
  int			size;

  if (!(buffer = malloc(sizeof(*buffer))))
    return (NULL);
  buffer->width = width;
  buffer->height = height;
  size = width * height * 4;
  if (!(pixels = malloc(sizeof(*pixels) * size)))
    return (NULL);
  i = 0;
  while (i < size)
    pixels[i++] = 255;
  buffer->pixels = pixels;
  return (buffer);
}
