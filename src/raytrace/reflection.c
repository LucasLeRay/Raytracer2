/*
** reflection.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Fri May  5 17:46:22 2017 Thery Fouchter
** Last update Sat May 27 17:07:51 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector3f	calc_reflection(sfVector3f i, sfVector3f n)
{
  return (v_sub_v(i, v_mult_nb(n, 2.0 * v_dot(i, n))));
}

int		trace_reflection_ray(t_raytracer *raytracer, t_ray *ray,
				     t_objects *obj_hit)
{
  t_ray		reflection_ray;
  sfColor	reflection_color;

  if (obj_hit->coef_reflexion <= 0)
    return (0);
  reflection_ray.ori = v_add_v(ray->pos_hit, v_mult_nb(ray->nrm_hit, 0.001));
  reflection_ray.dir = v_nrm(calc_reflection(ray->dir, ray->nrm_hit));
  reflection_ray.depth = ray->depth + 1;
  reflection_color = trace_ray(raytracer, &reflection_ray);
  ray->color = mix_color(reflection_color, obj_hit->coef_transparency,
			 ray->color, 1.0 - obj_hit->coef_transparency);
  return (1);
}
