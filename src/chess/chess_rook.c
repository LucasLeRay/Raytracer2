/*
** chess_rook.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Wed May 24 23:41:41 2017 Thery Fouchter
** Last update Thu May 25 22:04:08 2017 Thery Fouchter
*/

#include "raytracer.h"

static t_objects	*create_chess_rook_3(int side, sfVector3f pos)
{
  t_objects		*c_3;
  t_objects		*c_4;

  if (!(c_3 = malloc(sizeof(*c_3))) || !(c_4 = malloc(sizeof(*c_4))))
    return (NULL);
  init_node(c_3, "rook_crown_3");
  init_node(c_4, "rook_crown_4");
  set_objcolor_side(c_3, side);
  set_objcolor_side(c_4, side);
  c_3->type = (c_4->type = e_cone);
  c_3->size = (c_4->size = create_3vector(10, 5, 10));
  c_3->pos = create_3vector(pos.x - 10, pos.y, pos.z + 60);
  c_3->inc_pos = create_3vector(-10, 0, 60);
  c_4->pos = create_3vector(pos.x, pos.y - 10, pos.z + 60);
  c_4->inc_pos = create_3vector(0, -10, 60);
  c_3->next = c_4;
  return (c_3);
}

static t_objects	*create_chess_rook_2(int side, sfVector3f pos)
{
  t_objects		*c_1;
  t_objects		*c_2;

  if (!(c_1 = malloc(sizeof(*c_1))) || !(c_2 = malloc(sizeof(*c_2))))
    return (NULL);
  init_node(c_1, "rook_crown_1");
  init_node(c_2, "rook_crown_2");
  set_objcolor_side(c_1, side);
  set_objcolor_side(c_2, side);
  c_1->type = (c_2->type = e_cone);
  c_1->size = (c_2->size = create_3vector(10, 5, 10));
  c_1->pos = create_3vector(pos.x + 10, pos.y, pos.z + 60);
  c_1->inc_pos = create_3vector(10, 0, 60);
  c_2->pos = create_3vector(pos.x, pos.y + 10, pos.z + 60);
  c_2->inc_pos = create_3vector(0, 10, 60);
  c_1->next = c_2;
  c_2->next = create_chess_rook_3(side, pos);
  return (c_1);
}

t_objects	*create_chess_rook(int side, sfVector3f pos)
{
  t_objects	*body;
  t_objects	*up;

  if (!(body = malloc(sizeof(*body))) || !(up = malloc(sizeof(*up))))
    return (NULL);
  init_node(body, "rook_body");
  init_node(up, "rook_up");
  set_objcolor_side(body, side);
  set_objcolor_side(up, side);
  body->type = e_cylinder;
  body->size = create_3vector(15, 0, 75);
  body->pos = create_3vector(pos.x, pos.y, pos.z + 50);
  body->inc_pos = create_3vector(0, 0, 50);
  up->type = e_sphere;
  up->size = create_3vector(15, 20, 20);
  up->pos = create_3vector(pos.x, pos.y, pos.z + 40);
  up->inc_pos = create_3vector(0, 0, 40);
  body->next = up;
  up->next = create_chess_rook_2(side, pos);
  return (ass(body, c3v(75, 75, 75), c3v(pos.x, pos.y, pos.z + 25)));
}
