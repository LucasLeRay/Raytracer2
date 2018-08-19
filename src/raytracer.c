/*
** raytracer.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 11:59:43 2017 Thery Fouchter
** Last update Sun May 28 23:22:53 2017 Guts
*/

#include "raytracer.h"

pthread_t	g_tid[NBR_THREAD];
int		g_pos[NBR_THREAD];

int		main_raytracer_loop(t_raytracer *raytracer)
{
  sfEvent	event;
  int		refresh;

  refresh = 0;
  while (sfRenderWindow_pollEvent(raytracer->visual->window, &event))
    refresh += handle_win_events(raytracer, &event);
  if ((refresh += apply_physics(raytracer)))
  handle_key_events(raytracer);
  if (refresh || handle_key_events(raytracer)
      || (raytracer->opti == 1 && !(raytracer->opti = 0)))
    {
      raytrace(raytracer);
      update_visual(raytracer->visual, 1);
      activate_timed_rotation(raytracer);
    }
  sfRenderWindow_display(raytracer->visual->window);
  return (0);
}

t_my_framebuffer	*init_rendering(t_my_framebuffer *mem)
{
  t_my_framebuffer	*list;
  int			i;
  int			size;

  i = -1;
  if ((list = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  list->width = mem->width;
  list->height = mem->height;
  size = list->width * list->height * 4;
  if ((list->pixels = malloc(sizeof(sfUint8) * (size))) == NULL)
    return (NULL);
  while (++i < size)
    list->pixels[i] = mem->pixels[i];
  list->next = NULL;
  return (list);
}

t_my_framebuffer	*start_rendering(t_raytracer *raytracer, int max)
{
  t_my_framebuffer	*list;
  t_my_framebuffer	*tmp;
  t_my_framebuffer	*loading;
  sfEvent		event;
  int			i;

  raytracer->opti = 0;
  tmp = (list = init_rendering(raytracer->visual->framebuffer));
  loading = init_rendering(raytracer->visual->framebuffer);
  i = -1;
  init_loading_screen(raytracer, loading);
  while (++i < max)
    {
      loading_screen(raytracer, i * 100 / max, loading);
      while (sfRenderWindow_pollEvent(raytracer->visual->window, &event))
	handle_win_events(raytracer, &event);
      handle_key_events(raytracer);
      raytracer->visual->framebuffer = tmp;
      raytrace(raytracer);
      activate_timed_rotation(raytracer);
      apply_physics(raytracer);
      tmp = (tmp->next = init_rendering(raytracer->visual->framebuffer));
    }
  loading_done(raytracer, loading);
  return (list);
}

int			show_rendering(t_raytracer *raytracer, t_my_framebuffer *list)
{
  t_my_framebuffer	*backup;
  t_my_framebuffer	*tmp;
  sfEvent		event;

  backup = raytracer->visual->framebuffer;
  tmp = list;
  while (sfRenderWindow_isOpen(raytracer->visual->window))
    {
      while (sfRenderWindow_pollEvent(raytracer->visual->window, &event))
	handle_win_events(raytracer, &event);
      raytracer->visual->framebuffer = tmp;
      update_visual(raytracer->visual, 1);
      sfRenderWindow_display(raytracer->visual->window);
      if (!(tmp = tmp->next))
	tmp = list;
      sfSleep(sfMilliseconds(5));
    }
  raytracer->visual->framebuffer = backup;
  return (0);
}

int			raytracer(int ac, char **av)
{
  t_raytracer		*raytracer;
  t_my_framebuffer	*list;

  if (!(raytracer = malloc(sizeof(*raytracer)))
      || !(raytracer->parser = parsing(ac, av))
      || init_raytracer(raytracer) == -1)
    return (84);
  init_music(raytracer);
  raytracer->img = read_PPM("ressources/bump_rock.ppm");
  raytracer->camera->pos = create_3vector(0, 0, 0);
  raytrace(raytracer);
  update_visual(raytracer->visual, 1);
  if (raytracer->parser->parsing->rendering > -1)
    {
      list = start_rendering(raytracer, raytracer->parser->parsing->rendering);
      return (show_rendering(raytracer, list));
    }
  while (sfRenderWindow_isOpen(raytracer->visual->window))
    main_raytracer_loop(raytracer);
  if (raytracer->parser->parsing->music != NULL)
    sfMusic_destroy(raytracer->parser->parsing->music);
  return (0);
}
