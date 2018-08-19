/*
** super_sampling.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Tue May 23 12:52:11 2017 Thery Fouchter
** Last update Sun May 28 21:17:30 2017 Thery Fouchter
*/

#include "raytracer.h"

sfColor		super_sampling(t_raytracer *raytracer, sfVector2f p,
			       sfColor color, t_ray *ray)
{
  double	offset;
  int		super_sampling;

  if (raytracer->opti)
    return (color);
  super_sampling = raytracer->parser->parsing->antialiasing;
  while (super_sampling > 0)
    {
      offset = 25;
      setup_ray(raytracer, ray, create_2vector(p.x + offset, p.y + offset));
      color = mix_color(color, 0.5, trace_ray(raytracer, ray), 0.5);
      setup_ray(raytracer, ray, create_2vector(p.x + offset, p.y - offset));
      color = mix_color(color, 0.5, trace_ray(raytracer, ray), 0.5);
      setup_ray(raytracer, ray, create_2vector(p.x - offset, p.y + offset));
      color = mix_color(color, 0.5, trace_ray(raytracer, ray), 0.5);
      setup_ray(raytracer, ray, create_2vector(p.x - offset, p.y - offset));
      color = mix_color(color, 0.5, trace_ray(raytracer, ray), 0.5);
      super_sampling -= 4;
    }
  return (color);
}
