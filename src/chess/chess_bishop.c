/*
** chess_bishop.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Wed May 24 23:06:17 2017 Thery Fouchter
** Last update Thu May 25 21:57:20 2017 Thery Fouchter
*/

#include "raytracer.h"

t_objects	*create_chess_bishop(int side, sfVector3f pos)
{
  t_objects	*body;
  t_objects	*up;

  if (!(body = malloc(sizeof(*body))) || !(up = malloc(sizeof(*up))))
    return (NULL);
  init_node(body, "bishop_body");
  init_node(up, "bishop_up");
  set_objcolor_side(body, side);
  set_objcolor_side(up, side);
  body->type = e_cone;
  body->size = create_3vector(50, 0, 85);
  body->pos = create_3vector(pos.x, pos.y, pos.z + 60);
  body->inc_pos = create_3vector(0, 0, 60);
  up->type = e_sphere;
  up->size = create_3vector(17, 17, 17);
  up->pos = create_3vector(pos.x, pos.y, pos.z + 60);
  up->inc_pos = create_3vector(0, 0, 60);
  body->next = up;
  return (ass(body, c3v(75, 75, 75), c3v(pos.x, pos.y, pos.z + 25)));
}
