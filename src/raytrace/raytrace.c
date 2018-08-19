/*
** raytrace.c for  in /home/Thery/Desktop/raytracer2/src
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 13:45:32 2017 Thery Fouchter
** Last update Fri May 26 00:27:14 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector3f	calc_dir_vector_float(float dist_to_plane,
				      sfVector2i screen_size,
				      sfVector2f screen_pos)
{
  sfVector3f	dir;

  dir.x = dist_to_plane;
  dir.y = (screen_size.x >> 1) - screen_pos.x;
  dir.z = (screen_size.y >> 1) - screen_pos.y;
  return (dir);
}

int	setup_ray(t_raytracer *raytracer, t_ray *ray, sfVector2f screen_pos)
{
  ray->dir = calc_dir_vector_float(raytracer->camera->dist_to_plane,
				   raytracer->visual->screen_size,
				   screen_pos);
  ray->dir = rotate_xyz(ray->dir, raytracer->camera->rot);
  ray->ori = raytracer->camera->pos;
  ray->depth = 0;
  ray->screen_pos = screen_pos;
  return (0);
}

sfColor		get_wallpaper_color(t_raytracer *raytracer, t_ray *ray)
{
  t_ppm_texture	*texture;
  sfVector2f	uv;
  sfVector2i	size;
  sfColor	color;
  int		index;

  color = sfWhite;
  if ((texture = raytracer->parser->parsing->wallpaper_ppm))
    {
      uv = convert_xyz_to_cube_uv(ray->dir, &index);
      size = texture->size;
      size.x = (int)(size.x * uv.x) % texture->size.x;
      size.y = (int)(size.y * uv.y) % texture->size.y;
      color = texture->image[size.y][size.x];
    }
  return (color);
}

sfColor		trace_ray(t_raytracer *raytracer, t_ray *ray)
{
  t_objects	*obj_hit;
  float		k;

  if (!(obj_hit = get_closest_intersect(raytracer->obj->next, ray->ori,
					ray->dir, &k)))
    return (get_wallpaper_color(raytracer, ray));
  else if (raytracer->opti == 1 || calc_ray_vectors(ray, obj_hit, k) == -1)
    return (obj_hit->color);
  ray->color = calc_cube_mapping(raytracer, ray, obj_hit);
  ray->color = calc_normal_mapping(raytracer, ray, obj_hit);
  ray->color = calc_perlin_noise(raytracer, ray, obj_hit);
  if ((obj_hit->coef_reflexion > 0 || obj_hit->coef_refraction > 0)
      && ray->depth < raytracer->parser->parsing->max_recursion)
    {
      trace_reflection_ray(raytracer, ray, obj_hit);
      trace_refraction_ray(raytracer, ray, obj_hit);
    }
  return (trace_light_ray(raytracer, ray, obj_hit));
}

int		raytrace(t_raytracer *raytracer)
{
  sfVector2f	screen_pos;
  t_ray		ray;
  sfColor	color;

  if (!raytrace_thread_scene(raytracer))
    return (0);
  screen_pos.y = -1;
  while (++screen_pos.y < raytracer->visual->framebuffer->height)
    {
      screen_pos.x = -1;
      while (++screen_pos.x < raytracer->visual->framebuffer->width)
	{
	  setup_ray(raytracer, &ray, screen_pos);
	  color = trace_ray(raytracer, &ray);
	  color = super_sampling(raytracer, screen_pos, color, &ray);
	  my_put_pixel(raytracer->visual->framebuffer, screen_pos.x,
		       screen_pos.y, color);
	}
    }
  return (0);
}
