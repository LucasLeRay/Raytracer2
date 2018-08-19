/*
** calc_vector.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/raytracer2/src/physics
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri May 26 17:30:30 2017 Guts
** Last update Sat May 27 16:59:40 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector3f	calc_direction(t_objects *obj, t_objects *obj2)
{
  sfVector3f	direction;

  direction.x = (obj2->pos.x - obj->pos.x);
  direction.y = (obj2->pos.y - obj->pos.y);
  direction.z = (obj2->pos.z - obj->pos.z);
  return (direction);
}

void	calc_vector_coll(sfVector3f final, t_objects *obj,
			 __attribute__((unused))t_objects *obj2)
{
  obj->check_speed = 1;
  obj->speed.x += final.x * 1.0 / pow(obj->mass, 2.0);
  obj->speed.y += final.y * 1.0 / pow(obj->mass, 2.0);
  obj->speed.z += final.z * 1.0 / pow(obj->mass, 2.0);
}

sfVector3f	calc_final_vector(sfVector3f final, t_objects *obj)
{
  if (obj->check_speed == 1)
    {
      final.x += obj->speed.x;
      final.y += obj->speed.y;
      final.z += obj->speed.z;
      obj->speed.x = final.x;
      obj->speed.y = final.y;
      obj->speed.z = final.z;
    }
  final.x += obj->pos.x;
  final.y += obj->pos.y;
  final.z += obj->pos.z;
  return (final);
}
