/*
** visual.c for  in /home/Thery/Desktop/raytracer2/src
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 13:41:16 2017 Thery Fouchter
** Last update Thu Mar 23 19:43:55 2017 Thery Fouchter
*/

#include "raytracer.h"

t_visual	*init_visual(t_parser *parser)
{
  t_visual	*visual;
  int		width;
  int		height;

  width = parser->win_x;
  height = parser->win_y;
  if (!(visual = malloc(sizeof(*visual)))
      || !(visual->window = init_window(width, height))
      || !(visual->framebuffer = init_framebuffer(width, height))
      || !(visual->sprite = sfSprite_create())
      || !(visual->texture = sfTexture_create(width, height)))
    return (NULL);
  sfSprite_setTexture(visual->sprite, visual->texture, sfTrue);
  visual->screen_size.x = width;
  visual->screen_size.y = height;
  return (visual);
}

int	update_visual(t_visual *visual, int clear)
{
  sfTexture_updateFromPixels(visual->texture,
			     visual->framebuffer->pixels,
			     visual->framebuffer->width,
			     visual->framebuffer->height,
			     0, 0);
  if (clear)
    sfRenderWindow_clear(visual->window, sfBlack);
  sfRenderWindow_drawSprite(visual->window, visual->sprite, NULL);
  return (0);
}
