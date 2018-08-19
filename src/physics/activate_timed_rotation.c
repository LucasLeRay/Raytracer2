/*
** activate_timed_rotation.c for raytracer2 in /home/guts/Projects/raytracer2/src/physics
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Sun May 28 22:30:59 2017 Guts
** Last update Sun May 28 23:29:30 2017 Guts
*/

#include "raytracer.h"

void		activate_timed_rotation(t_raytracer *raytracer)
{
  t_objects	*mem;

  mem = raytracer->obj;
  while (raytracer->obj)
    {
      raytracer->obj->rotation.x += raytracer->obj->timed_rotation.x;
      raytracer->obj->rotation.y += raytracer->obj->timed_rotation.y;
      raytracer->obj->rotation.z += raytracer->obj->timed_rotation.z;
      raytracer->obj = raytracer->obj->next;
    }
  raytracer->obj = mem;
}
