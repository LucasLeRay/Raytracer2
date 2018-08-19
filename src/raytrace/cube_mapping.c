/*
** cube_mapping.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Tue May 23 20:38:07 2017 Thery Fouchter
** Last update Sat May 27 17:08:23 2017 Thery Fouchter
*/

#include "raytracer.h"

static sfVector2f	setup_uv(float u, float v, float *max_axis, float max)
{
  *max_axis = max;
  return (create_2vector(u, v));
}

sfVector2f	convert_xyz_to_cube_uv(sfVector3f pos, int *index)
{
  sfVector2f	uv;
  sfVector3f	abs;
  float		max_axis;

  abs.x = ABS(pos.x);
  abs.y = ABS(pos.y);
  abs.z = ABS(pos.z);
  max_axis = abs.x;
  if (pos.x > 0 && abs.x >= abs.y && abs.x >= abs.z && !(*index = 0))
    uv = setup_uv(-pos.z, pos.y, &max_axis, abs.x);
  else if (pos.x <= 0 && abs.x >= abs.y && abs.x >= abs.z && (*index = 1))
    uv = setup_uv(pos.z, pos.y, &max_axis, abs.x);
  else if (pos.y > 0 && abs.y >= abs.x && abs.y >= abs.z && (*index = 2))
    uv = setup_uv(pos.x, -pos.z, &max_axis, abs.y);
  else if (pos.y <= 0 && abs.y >= abs.x && abs.y >= abs.z && (*index = 3))
    uv = setup_uv(pos.x, pos.z, &max_axis, abs.y);
  else if (pos.z > 0 && abs.z >= abs.x && abs.z >= abs.y && (*index = 4))
    uv = setup_uv(pos.x, pos.y, &max_axis, abs.z);
  else if (pos.z <= 0 && abs.z >= abs.x && abs.z >= abs.y && (*index = 5))
    uv = setup_uv(-pos.x, pos.y, &max_axis, abs.z);
  uv.x = 0.5 * (uv.x / max_axis + 1.0);
  uv.y = 0.5 * (uv.y / max_axis + 1.0);
  return (uv);
}

sfColor		calc_cube_mapping(__attribute__((unused))t_raytracer *r,
				  t_ray *ray, t_objects *obj_hit)
{
  sfVector3f	cube;
  sfVector2f	uv;
  sfVector2i	size;
  int		index;

  if (obj_hit->texture)
    {
      cube.x = ray->nrm_hit.y;
      cube.y = (ray->inside_obj ? ray->nrm_hit.z : -ray->nrm_hit.z);
      cube.z = ray->nrm_hit.x;
      index = 0;
      uv = convert_xyz_to_cube_uv(cube, &index);
      if (index >= 0 && index <= 5 && obj_hit->texture[index])
	{
	  size.x = obj_hit->texture[index]->size.x;
	  size.y = obj_hit->texture[index]->size.y;
	  size.x = (int)(size.x * uv.x) % obj_hit->texture[index]->size.x;
	  size.y = (int)(size.y * uv.y) % obj_hit->texture[index]->size.y;
	  ray->color = obj_hit->texture[index]->image[size.y][size.x];
	}
    }
  return (ray->color);
}
