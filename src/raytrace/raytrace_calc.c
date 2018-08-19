/*
** raytrace_calc.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Sun May  7 19:13:19 2017 Thery Fouchter
** Last update Sat May 27 15:14:15 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector3f	calc_normal(t_objects *obj, sfVector3f hit,
			    __attribute__((unused))sfVector3f dir)
{
  sfVector3f	n;

  n = hit;
  if (obj->type == e_sphere)
    n = get_normal_obj_sphere(obj, hit);
  else if (obj->type == e_plane)
    n = get_normal_plane(1);
  else if (obj->type == e_cylinder)
    n = get_normal_cylinder(hit);
  else if (obj->type == e_cone)
    n = get_normal_cone(hit, obj->size.x);
  else
    n = get_normal_obj_sphere(obj, hit);
  return (n);
}

sfVector3f	calc_pos_hit(sfVector3f ori, sfVector3f dir, float k)
{
  sfVector3f	pos_hit;

  pos_hit.x = ori.x + dir.x * k;
  pos_hit.y = ori.y + dir.y * k;
  pos_hit.z = ori.z + dir.z * k;
  return (pos_hit);
}

int	calc_ray_vectors(t_ray *ray, t_objects *obj_hit, float k)
{
  if (!v_diff(obj_hit->rotation, create_null_3vector()))
    {
      ray->dir = rotate_xyz(ray->dir, obj_hit->rotation);
      ray->ori = rotate_zyx(ray->ori, obj_hit->rotation);
    }
  ray->pos_hit = calc_pos_hit(ray->ori, ray->dir, k);
  ray->nrm_hit = v_nrm(calc_normal(obj_hit, ray->pos_hit, ray->dir));
  ray->inside_obj = 0;
  if (v_dot(ray->dir, ray->nrm_hit) > 0 && (ray->inside_obj = 1))
    ray->nrm_hit = v_mult_nb(ray->nrm_hit, -1.0);
  if (obj_hit)
    ray->color = apply_pattern_color(obj_hit->color, obj_hit->pattern_color,
				     ray->pos_hit, obj_hit->pattern);
  return (0);
}
