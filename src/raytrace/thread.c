/*
** thread.c<raytrace> for  in /home/thery/Desktop/raytracer2
** 
** Made by Thery
** Login   <thery.fouchter@epitech.eu>
** 
** Started on  Mon Apr 17 17:31:22 2017 Thery
** Last update Sat May 27 17:09:40 2017 Thery Fouchter
*/

#include "raytracer.h"

void		*raytrace_thread(void *raytracer_void)
{
  t_ray		ray;
  sfVector2f	sp;
  t_raytracer	*raytracer;
  pthread_t	id;
  int		i;

  raytracer = (t_raytracer *)raytracer_void;
  id = pthread_self();
  i = -1;
  while (++i < NBR_THREAD && !pthread_equal(id, g_tid[i]));
  sp.y = 0;
  while (sp.y < raytracer->visual->framebuffer->height)
    {
      sp.x = g_pos[i];
      while (sp.x < raytracer->visual->framebuffer->width)
	{
	  setup_ray(raytracer, &ray, sp);
	  ray.color = trace_ray(raytracer, &ray);
	  ray.color = super_sampling(raytracer, sp, ray.color, &ray);
	  my_put_pixel(raytracer->visual->framebuffer, sp.x, sp.y, ray.color);
	  sp.x += NBR_THREAD + (raytracer->opti == 1 ? OPTI_JUMP : 0);
	}
      sp.y += (raytracer->opti == 1 ? OPTI_JUMP : 1);
    }
  return (NULL);
}

int	raytrace_thread_scene(t_raytracer *ray)
{
  int	i;
  int	start;

  start = -1;
  i = -1;
  while (++i < NBR_THREAD)
    {
      g_pos[i] = ++start;
      if (pthread_create(&g_tid[i], NULL, &raytrace_thread, (void *)ray))
	return (-i);
    }
  i = -1;
  while (++i < NBR_THREAD)
    pthread_join(g_tid[i], NULL);
  return (0);
}
