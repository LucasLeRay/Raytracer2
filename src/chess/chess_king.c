/*
** chess_king.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Thu May 25 02:45:08 2017 Thery Fouchter
** Last update Thu May 25 22:08:16 2017 Thery Fouchter
*/

#include "raytracer.h"

static t_objects	*create_chess_king_4(int side, sfVector3f pos)
{
  t_objects		*cross_ver;
  t_objects		*cross_hor;

  if (!(cross_ver = malloc(sizeof(*cross_ver)))
      || !(cross_hor = malloc(sizeof(*cross_hor))))
    return (NULL);
  init_node(cross_ver, "king_cross_ver");
  init_node(cross_hor, "king_cross_hor");
  set_objcolor_side(cross_ver, side);
  set_objcolor_side(cross_hor, side);
  cross_ver->type = e_plane;
  cross_ver->size = create_3vector(5, 20, 5);
  cross_ver->rotation = create_3vector(-90, 0, 0);
  cross_ver->pos = create_3vector(pos.x, pos.y, pos.z + 60);
  cross_ver->inc_pos = create_3vector(0, 0, 60);
  cross_hor->type = e_plane;
  cross_hor->size = create_3vector(10, 5, 5);
  cross_hor->rotation = create_3vector(-90, 0, 0);
  cross_hor->pos = create_3vector(pos.x, pos.y, pos.z + 67);
  cross_hor->inc_pos = create_3vector(0, 0, 67);
  cross_ver->next = cross_hor;
  return (cross_ver);
}

static t_objects	*create_chess_king_3(int side, sfVector3f pos)
{
  t_objects		*c_3;
  t_objects		*c_4;

  if (!(c_3 = malloc(sizeof(*c_3))) || !(c_4 = malloc(sizeof(*c_4))))
    return (NULL);
  init_node(c_3, "king_crown_3");
  init_node(c_4, "king_crown_4");
  set_objcolor_side(c_3, side);
  set_objcolor_side(c_4, side);
  c_3->type = (c_4->type = e_cone);
  c_3->size = (c_4->size = create_3vector(10, 5, 10));
  c_3->pos = create_3vector(pos.x - 10, pos.y, pos.z + 60);
  c_3->inc_pos = create_3vector(-10, 0, 60);
  c_4->pos = create_3vector(pos.x, pos.y - 10, pos.z + 60);
  c_4->inc_pos = create_3vector(0, -10, 60);
  c_3->next = c_4;
  c_4->next = create_chess_king_4(side, pos);
  return (c_3);
}

static t_objects	*create_chess_king_2(int side, sfVector3f pos)
{
  t_objects		*c_1;
  t_objects		*c_2;

  if (!(c_1 = malloc(sizeof(*c_1))) || !(c_2 = malloc(sizeof(*c_2))))
    return (NULL);
  init_node(c_1, "king_crown_1");
  init_node(c_2, "king_crown_2");
  set_objcolor_side(c_1, side);
  set_objcolor_side(c_2, side);
  c_1->type = (c_2->type = e_cone);
  c_1->size = (c_2->size = create_3vector(10, 5, 10));
  c_1->pos = create_3vector(pos.x + 10, pos.y, pos.z + 60);
  c_1->inc_pos = create_3vector(10, 0, 60);
  c_2->pos = create_3vector(pos.x, pos.y + 10, pos.z + 60);
  c_1->inc_pos = create_3vector(0, 10, 60);
  c_1->next = c_2;
  c_2->next = create_chess_king_3(side, pos);
  return (c_1);
}

t_objects	*create_chess_king(int side, sfVector3f pos)
{
  t_objects	*body;
  t_objects	*up;

  if (!(body = malloc(sizeof(*body))) || !(up = malloc(sizeof(*up))))
    return (NULL);
  init_node(body, "king_body");
  init_node(up, "king_up");
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
  up->next = create_chess_king_2(side, pos);
  return (ass(body, c3v(75, 75, 75), c3v(pos.x, pos.y, pos.z + 25)));
}
