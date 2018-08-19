/*
** window.c for  in /home/Thery/Desktop/raytracer2/src
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 13:42:48 2017 Thery Fouchter
** Last update Wed Mar 22 13:42:57 2017 Thery Fouchter
*/

#include "raytracer.h"

sfRenderWindow		*init_window(int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = BITS_PER_PXL;
  window = sfRenderWindow_create(mode, MAIN_TITLE, WIN_STYLE, NULL);
  sfRenderWindow_clear(window, sfBlack);
  return (window);
}
