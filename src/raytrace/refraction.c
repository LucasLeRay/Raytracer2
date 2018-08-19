/*
** refraction.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Fri May  5 17:47:10 2017 Thery Fouchter
** Last update Sun May 28 21:45:44 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector3f	calc_refraction(sfVector3f i, sfVector3f n, float n1, float n2)
{
  float		delta_n;
  float		cos_theta1;
  float		cos_sq_theta2;

  delta_n = (n1 - n2) / (n1 + n2);
  delta_n *= delta_n;
  cos_theta1 = -v_dot(i, n);
  cos_sq_theta2 = 1.0 - delta_n * delta_n * (1.0 - cos_theta1 * cos_theta1);
  if (cos_sq_theta2 < 0.0)
    return (create_null_3vector());
  return (v_add_v(v_mult_nb(i, delta_n),
		  v_mult_nb(n, delta_n * cos_theta1 - sqrt(cos_sq_theta2))));
}

int		trace_refraction_ray(t_raytracer *raytracer, t_ray *ray,
				     t_objects *obj_hit)
{
  t_ray		refraction_ray;
  sfColor	refraction_color;
  sfVector3f	refracted_ray;

  if (obj_hit->coef_refraction <= 0)
    return (0);
  if (ray->inside_obj)
    refracted_ray = calc_refraction(ray->dir, ray->nrm_hit,
				    obj_hit->coef_refraction, 1.0);
  else
    refracted_ray = calc_refraction(ray->dir, ray->nrm_hit, 1.0,
				    obj_hit->coef_refraction);
  if (v_diff(refracted_ray, create_null_3vector()))
    return (0);
  refraction_ray.ori = v_sub_v(ray->pos_hit, v_mult_nb(ray->nrm_hit, 0.001));
  refraction_ray.dir = v_nrm(refracted_ray);
  refraction_ray.depth = ray->depth + 1;
  refraction_color = trace_ray(raytracer, &refraction_ray);
  ray->color = mix_color(refraction_color, obj_hit->coef_transparency,
			 ray->color, 1.0 - obj_hit->coef_transparency);
  return (1);
}
