/*
** calc_newton.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/raytracer2/src/physics
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri May 26 17:22:26 2017 Guts
** Last update Fri May 26 17:27:11 2017 Guts
*/

#include "raytracer.h"

double		calc_newton(t_objects *obj, t_objects *obj2,
			    sfVector3f direction)
{
  double	newton;
  float		distance;
  int		check;

  check = 0;
  distance = sqrt(pow((direction.x), 2.0)
		  + pow((direction.y), 2.0)
		  + pow((direction.z), 2.0));
  if (distance < 0)
    distance *= (-1.0);
  if (distance < obj->size.x + obj2->size.x)
    check = 1;
  distance *= distance;
  newton = G * ((obj->mass * obj2->mass) / distance);
  if (check == 1)
    newton *= (-1.0);
  return (newton);
}

sfVector3f	apply_force_vector(sfVector3f direction, double newton,
				   float mass)
{
  sfVector3f	final;

  final.x = (direction.x * newton) / mass;
  final.y = (direction.y * newton) / mass;
  final.z = (direction.z * newton) / mass;
  return (final);
}
