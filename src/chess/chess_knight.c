/*
** chess_knight.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Wed May 24 22:54:50 2017 Thery Fouchter
** Last update Sat May 27 17:26:37 2017 Thery Fouchter
*/

#include "raytracer.h"

static t_objects	*create_chess_knight_3(int side, sfVector3f pos)
{
  t_objects		*right_eye;
  t_objects		*bottom;

  if (!(right_eye = malloc(sizeof(*right_eye)))
      || !(bottom = malloc(sizeof(*bottom))))
    return (NULL);
  init_node(right_eye, "knight_right_eye");
  init_node(bottom, "knight_bottom");
  set_objcolor_side(right_eye, side);
  set_objcolor_side(bottom, side);
  right_eye->type = e_sphere;
  right_eye->size = create_3vector(10, 10, 10);
  right_eye->pos = create_3vector(pos.x - 10, pos.y, pos.z + 50);
  right_eye->inc_pos = create_3vector(-10, 0, 50);
  bottom->type = e_sphere;
  bottom->size = create_3vector(15, 15, 15);
  bottom->pos = create_3vector(pos.x, pos.y, pos.z);
  bottom->inc_pos = create_3vector(0, 0, 0);
  right_eye->next = bottom;
  return (right_eye);
}

static t_objects	*create_chess_knight_2(int side, sfVector3f p)
{
  t_objects		*neck_head;
  t_objects		*left_eye;

  if (!(neck_head = malloc(sizeof(*neck_head)))
      || !(left_eye = malloc(sizeof(*left_eye))))
    return (NULL);
  init_node(neck_head, "knight_neck_head");
  init_node(left_eye, "knight_left_eye");
  set_objcolor_side(neck_head, side);
  set_objcolor_side(left_eye, side);
  neck_head->type = e_sphere;
  neck_head->size = create_3vector(15, 15, 15);
  neck_head->pos = create_3vector(p.x, p.y + (side ? -20 : 20), p.z + 30);
  neck_head->inc_pos = create_3vector(0, (side ? -20 : 20), 30);
  left_eye->type = e_sphere;
  left_eye->size = create_3vector(10, 10, 10);
  left_eye->pos = create_3vector(p.x + 10, p.y, p.z + 50);
  left_eye->inc_pos = create_3vector(10, 0, 50);
  neck_head->next = left_eye;
  left_eye->next = create_chess_knight_3(side, p);
  return (neck_head);
}

t_objects	*create_chess_knight(int side, sfVector3f pos)
{
  t_objects	*body;
  t_objects	*neck;
  t_objects	*head;

  if (!(body = malloc(sizeof(*body))) || !(neck = malloc(sizeof(*neck))))
    return (NULL);
  init_node(body, "knight_body");
  init_node(neck, "knight_neck");
  init_node((head = malloc(sizeof(*head))), "knight_head");
  set_objcolor_side(body, side);
  set_objcolor_side(neck, side);
  set_objcolor_side(head, side);
  body->type = (neck->type = e_cylinder);
  body->size = create_3vector(15, 0, 75);
  neck->pos = (body->pos = create_3vector(pos.x, pos.y, pos.z + 50));
  head->inc_pos = (body->inc_pos = (neck->inc_pos = create_3vector(0, 0, 50)));
  neck->size = create_3vector(15, 0, 25);
  neck->rotation = create_3vector((side ? 45 : -45), 0, 0);
  head->type = e_sphere;
  head->size = create_3vector(17, 17, 17);
  head->pos = create_3vector(pos.x, pos.y, pos.z + 50);
  body->next = neck;
  neck->next = head;
  head->next = create_chess_knight_2(side, pos);
  return (ass(body, c3v(75, 75, 75), c3v(pos.x, pos.y, pos.z + 25)));
}
