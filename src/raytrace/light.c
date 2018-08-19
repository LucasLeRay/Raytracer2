/*
** light.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Sun May  7 20:05:26 2017 Thery Fouchter
** Last update Thu May 25 11:10:18 2017 Thery Fouchter
*/

#include "raytracer.h"

sfColor		trace_light_ray(t_raytracer *raytracer, t_ray *ray,
				t_objects *obj_hit)
{
  t_light	l;
  sfColor	color;
  t_objects	*li;
  t_objects	*shadow;
  double	mix;
  int		i;

  color = ray->color;
  i = -1;
  while (raytracer->lights && (li = raytracer->lights[++i]))
    {
      l.light_dir = v_nrm(v_sub_v(li->pos, ray->pos_hit));
      l.light_pos = v_add_v(ray->pos_hit, v_mult_nb(ray->nrm_hit, 0.001));
      shadow = get_closest_intersect(raytracer->obj->next, l.light_pos,
				     l.light_dir, NULL);
      l.color = color;
      calc_phong_color(ray, obj_hit, &l, shadow);
      mix = CLAMP(obj_hit->coef_transparency, 0.0, 1.0);
      color = mix_color(color, mix, l.color, 1.0 - mix);
    }
  return (color);
}

sfColor		calc_phong_color(t_ray *ray, t_objects *obj_hit,
				 t_light *l, t_objects *shadow)
{
  double	intensity;

  l->ambient = calc_ambient(obj_hit, &l->k_ambient);
  l->color = mix_color(l->color, 1.0 - l->k_ambient,
		       l->ambient, l->k_ambient);
  if (shadow)
    l->color = mult_color(l->color, 0.3);
  l->diffuse = calc_diffuse(obj_hit, ray, l->light_dir, &l->k_diffuse);
  l->specular = calc_specular(obj_hit, ray, l->light_dir, &l->k_specular);
  intensity = (l->k_diffuse + l->k_specular);
  intensity = MAX(0.0, l->k_ambient + intensity);
  l->color = mult_color(l->color, intensity);
  l->color = mix_color(l->color, 1.0 - l->k_diffuse,
		       l->diffuse, l->k_diffuse);
  l->color = mix_color(l->color, 1.0 - l->k_specular,
		       l->specular, l->k_specular);
  return (l->color);
}

sfColor		calc_ambient(t_objects *obj_hit, double *k)
{
  double	k_ambient;

  k_ambient = CLAMP(obj_hit->coef_ambient, 0.0, 1.0);
  if (k)
    *k = k_ambient;
  return (mult_color(obj_hit->color_ambient, k_ambient));
}

sfColor		calc_diffuse(t_objects *obj_hit, t_ray *ray,
			     sfVector3f light_dir, double *k)
{
  double	k_diffuse;

  k_diffuse = CLAMP(v_dot(light_dir, ray->nrm_hit), 0.0, 1.0);
  k_diffuse *= obj_hit->coef_diffuse;
  if (k)
    *k = k_diffuse;
  return (mult_color(obj_hit->color_diffuse, k_diffuse));
}

sfColor		calc_specular(t_objects *obj_hit, t_ray *ray,
			      sfVector3f light_dir, double *k)
{
  double	k_specular;

  k_specular = v_dot(calc_reflection(light_dir, ray->nrm_hit),
		     v_nrm(ray->dir));
  k_specular = obj_hit->coef_specular * pow(k_specular,
					    obj_hit->specular_power);
  k_specular = CLAMP(k_specular, 0.0, 1.0);
  if (k)
    *k = k_specular;
  return (mult_color(obj_hit->color_specular, k_specular));
}
