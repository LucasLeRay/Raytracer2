/*
** chess_pos.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Wed May 24 21:33:26 2017 Thery Fouchter
** Last update Sat May 27 17:15:29 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector3f	get_chess_pos(t_objects *board, int x, int y)
{
  sfVector3f	ori;
  int		size;

  if (x < 0 || x > 7)
    return (create_null_3vector());
  size = 90;
  ori.x = board->pos.x - board->size.x + 40;
  ori.y = board->pos.y - board->size.y + 40;
  ori.z = board->pos.z + 25;
  return (create_3vector(ori.x + x * size, ori.y + y * size, ori.z));
}

int	set_objcolor_side(t_objects *obj, int color)
{
  if (color == 0 && !(obj->side = 0))
    obj->color = create_color(255, 238, 204, 255);
  else if (color == 1 && (obj->side = 1))
    obj->color = create_color(50, 50, 50, 255);
  else
    obj->color = create_color(255, 50, 50, 255);
  obj->color_ambient = create_color(obj->color.r, obj->color.g,
				    obj->color.b, obj->color.a);
  obj->color_diffuse = create_color(obj->color.r, obj->color.g,
				    obj->color.b, obj->color.a);
  obj->color_specular = create_color(obj->color.r, obj->color.g,
				     obj->color.b, obj->color.a);
  obj->coef_ambient = 0.1;
  obj->coef_diffuse = 0.8;
  obj->coef_specular = 0.4;
  obj->coef_transparency = 0.35;
  return (0);
}

t_objects	*append_to_obj(t_objects *obj, t_objects *new, int id)
{
  t_objects	*tmp;
  t_objects	*prev;

  prev = (tmp = obj);
  while (tmp && (tmp = tmp->next))
    prev = tmp;
  if (!prev)
    obj = new;
  else
    prev->next = new;
  new->id = id;
  return (obj);
}
