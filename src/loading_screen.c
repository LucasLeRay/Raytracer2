/*
** loadind_screen.c for raytracer2 in /home/guts/raytracer2/src
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Sun May 28 14:56:38 2017 Guts
** Last update Sun May 28 22:28:20 2017 Guts
*/

#include "raytracer.h"

void	loading_screen(t_raytracer *raytracer, int percentage,
		       t_my_framebuffer *loading)
{
  int	x;
  int	y;

  y = loading->height / 2 - 25;
  raytracer->visual->framebuffer = loading;
  while (++y < loading->height / 2 + 25)
    {
      x = loading->width / 2 - 295;
      while (++x < (loading->width / 2 - 295 + (5.9 * (percentage))))
	my_put_pixel(loading, x, y, sfBlue);
    }
  update_visual(raytracer->visual, 0);
  sfRenderWindow_display(raytracer->visual->window);
}

void	loading_done(t_raytracer *raytracer, t_my_framebuffer *loading)
{
  loading_screen(raytracer, 100, loading);
  while (sfKeyboard_isKeyPressed(sfKeySpace) != sfTrue);
}

void			init_loading_screen(t_raytracer *raytracer,
					    t_my_framebuffer *loading)
{
  int			x;
  int			y;

  y = -1;
  raytracer->visual->framebuffer = loading;
  while (++y < loading->height)
    {
      x = -1;
      while (++x < loading->width)
	if ((((y >= loading->height / 2 - 30 && y <= loading->height / 2 - 25)
	      || (y >= loading->height / 2 + 25 && y <= loading->height / 2 + 30))
	     && x >= loading->width / 2 - 295 && x <= loading->width / 2 + 295)
	    || (((x >= loading->width / 2 - 300 && x <= loading->width / 2 - 295)
		 || (x >= loading->width / 2 + 295 && x <= loading->width / 2 + 300))
		&& y >= loading->height / 2 - 30 && y <= loading->height / 2 + 30))
	  my_put_pixel(loading, x, y, sfWhite);
	else
	  my_put_pixel(loading, x, y, sfBlack);
    }
  update_visual(raytracer->visual, 1);
  sfRenderWindow_display(raytracer->visual->window);
}
