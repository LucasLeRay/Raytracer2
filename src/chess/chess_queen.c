/*
** chess_queen.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Thu May 25 02:05:20 2017 Thery Fouchter
** Last update Thu May 25 22:02:56 2017 Thery Fouchter
*/

#include "raytracer.h"

static t_objects	*create_chess_queen_5(int side, sfVector3f pos)
{
  t_objects		*c_7;
  t_objects		*c_8;

  if (!(c_7 = malloc(sizeof(*c_7))) || !(c_8 = malloc(sizeof(*c_8))))
    return (NULL);
  init_node(c_7, "queen_crown_5");
  init_node(c_8, "queen_crown_6");
  set_objcolor_side(c_7, side);
  set_objcolor_side(c_8, side);
  c_7->type = (c_8->type = e_sphere);
  c_7->size = (c_8->size = create_3vector(3, 3, 3));
  c_7->pos = create_3vector(pos.x + 10, pos.y, pos.z + 60);
  c_7->inc_pos = create_3vector(10, 0, 60);
  c_8->pos = create_3vector(pos.x, pos.y + 10, pos.z + 60);
  c_8->inc_pos = create_3vector(0, 10, 60);
  c_7->next = c_8;
  return (c_7);
}

static t_objects	*create_chess_queen_4(int side, sfVector3f pos)
{
  t_objects		*c_5;
  t_objects		*c_6;

  if (!(c_5 = malloc(sizeof(*c_5))) || !(c_6 = malloc(sizeof(*c_6))))
    return (NULL);
  init_node(c_5, "queen_crown_5");
  init_node(c_6, "queen_crown_6");
  set_objcolor_side(c_5, side);
  set_objcolor_side(c_6, side);
  c_5->type = (c_6->type = e_sphere);
  c_5->size = (c_6->size = create_3vector(3, 3, 3));
  c_5->pos = create_3vector(pos.x - 10, pos.y, pos.z + 60);
  c_5->inc_pos = create_3vector(-10, 0, 60);
  c_6->pos = create_3vector(pos.x, pos.y - 10, pos.z + 60);
  c_6->inc_pos = create_3vector(0, -10, 60);
  c_5->next = c_6;
  c_6->next = create_chess_queen_5(side, pos);
  return (c_5);
}

static t_objects	*create_chess_queen_3(int side, sfVector3f pos)
{
  t_objects		*c_3;
  t_objects		*c_4;

  if (!(c_3 = malloc(sizeof(*c_3))) || !(c_4 = malloc(sizeof(*c_4))))
    return (NULL);
  init_node(c_3, "queen_crown_3");
  init_node(c_4, "queen_crown_4");
  set_objcolor_side(c_3, side);
  set_objcolor_side(c_4, side);
  c_3->type = (c_4->type = e_cone);
  c_3->size = (c_4->size = create_3vector(10, 2, 10));
  c_3->pos = create_3vector(pos.x - 10, pos.y, pos.z + 60);
  c_3->inc_pos = create_3vector(-10, 0, 60);
  c_4->pos = create_3vector(pos.x, pos.y - 10, pos.z + 60);
  c_3->inc_pos = create_3vector(0, -10, 60);
  c_3->next = c_4;
  c_4->next = create_chess_queen_4(side, pos);
  return (c_3);
}

static t_objects	*create_chess_queen_2(int side, sfVector3f pos)
{
  t_objects		*c_1;
  t_objects		*c_2;

  if (!(c_1 = malloc(sizeof(*c_1))) || !(c_2 = malloc(sizeof(*c_2))))
    return (NULL);
  init_node(c_1, "queen_crown_1");
  init_node(c_2, "queen_crown_2");
  set_objcolor_side(c_1, side);
  set_objcolor_side(c_2, side);
  c_1->type = (c_2->type = e_cone);
  c_1->size = (c_2->size = create_3vector(12, 2, 10));
  c_1->pos = create_3vector(pos.x + 10, pos.y, pos.z + 60);
  c_1->inc_pos = create_3vector(10, 0, 60);
  c_2->pos = create_3vector(pos.x, pos.y + 10, pos.z + 60);
  c_2->inc_pos = create_3vector(0, 10, 60);
  c_1->next = c_2;
  c_2->next = create_chess_queen_3(side, pos);
  return (c_1);
}

t_objects	*create_chess_queen(int side, sfVector3f pos)
{
  t_objects	*body;
  t_objects	*up;

  if (!(body = malloc(sizeof(*body))) || !(up = malloc(sizeof(*up))))
    return (NULL);
  init_node(body, "queen_body");
  init_node(up, "queen_up");
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
  up->next = create_chess_queen_2(side, pos);
  return (ass(body, c3v(75, 75, 75), c3v(pos.x, pos.y, pos.z + 25)));
}
