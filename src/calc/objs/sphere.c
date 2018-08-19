/*
** sphere.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 14:47:22 2017 Thery Fouchter
** Last update Wed May 17 14:50:04 2017 aba yanis
*/

#include "raytracer.h"

float	intersect_sphere(sfVector3f eye_pos,
			 sfVector3f dir_vector,
			 float radius)
{
  float	a;
  float	b;
  float	c;

  a = v_dot(dir_vector, dir_vector);
  b = 2 * v_dot(dir_vector, eye_pos);
  c = v_dot(eye_pos, eye_pos) - (radius * radius);
  return (get_delta(a, b, c));
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}

sfVector3f	get_normal_obj_sphere(t_objects *obj,
				      sfVector3f intersection_point)
{
  return (v_sub_v(intersection_point, obj->pos));
}
