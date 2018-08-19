/*
** calc_new_pos.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/src/physics
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed May 24 19:30:52 2017 Guts
** Last update Sun May 28 21:42:30 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector3f	find_new_position(t_objects *obj, t_objects *first)
{
  double	newton;
  sfVector3f	final;
  sfVector3f	direction;

  final.x = 0;
  final.y = 0;
  final.z = 0;
  newton = 0;
  while (first)
    {
      if (first != obj && first->mass != 0)
	{
	  direction = calc_direction(obj, first);
	  newton = calc_newton(obj, first, direction);
	  direction = apply_force_vector(direction, newton, obj->mass);
	  final.x += direction.x;
	  final.y += direction.y;
	  final.z += direction.z;
	  if (newton < 0)
	    calc_vector_coll(final, obj, first);
	}
      first = first->next;
    }
  return (calc_final_vector(final, obj));
}

int		apply_physics(t_raytracer *raytracer)
{
  t_objects	*mem;
  int		check;

  mem = raytracer->obj;
  while (raytracer->obj)
    {
      if (raytracer->obj->mass > 0)
	raytracer->obj->pos_temp = find_new_position(raytracer->obj, mem);
      raytracer->obj = raytracer->obj->next;
    }
  raytracer->obj = mem;
  while (raytracer->obj)
    {
      if (raytracer->obj->mass > 0)
	{
	  if (check == 0 && v_diff(raytracer->obj->pos,
				   raytracer->obj->pos_temp) == 0)
	    check = 1;
	  raytracer->obj->pos = raytracer->obj->pos_temp;
	}
      raytracer->obj = raytracer->obj->next;
    }
  raytracer->obj = mem;
  return (check);
}
