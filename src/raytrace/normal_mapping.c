/*
** normal_mapping.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Tue May 23 23:02:15 2017 Thery Fouchter
** Last update Sun May 28 21:29:40 2017 Thery Fouchter
*/

#include "raytracer.h"

sfColor		calc_normal_mapping(t_raytracer *raytracer, t_ray *ray,
				    t_objects *obj_hit)
{
  sfVector3f	cube;
  sfVector2f	uv;
  sfVector2i	size;
  sfColor	color;
  int		index;

  if (raytracer->img && obj_hit->pattern & 64)
    {
      uv = convert_xyz_to_cube_uv(cube, &index);
      size.x = raytracer->img->size.x;
      size.y = raytracer->img->size.y;
      size.x = (int)(size.x * uv.x) % size.x;
      size.y = (int)(size.y * uv.y) % size.y;
      color = raytracer->img->image[size.y][size.x];
      ray->nrm_hit.x += (color.r / 255.0);
      ray->nrm_hit.y += (color.g / 255.0);
      if (color.b >= 128)
	ray->nrm_hit.z += (color.b / 255.0);
    }
  return (ray->color);
}
