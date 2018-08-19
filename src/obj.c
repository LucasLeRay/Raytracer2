/*
** obj.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Thu Mar 23 20:57:47 2017 Thery Fouchter
** Last update Fri May  5 00:27:16 2017 Thery Fouchter
*/

#include "raytracer.h"

t_objects	**get_lights(t_objects *obj)
{
  t_objects	**lights;
  t_objects	*tmp;
  int		nb_lights;
  int		pos_lights;

  if (!obj || !obj->next)
    return (NULL);
  nb_lights = 0;
  tmp = obj;
  while ((tmp = tmp->next))
    if (tmp->type & e_light)
      ++nb_lights;
  pos_lights = -1;
  if (!(lights = malloc(sizeof(*lights) * (nb_lights + 1))))
    return (NULL);
  tmp = obj;
  while ((tmp = tmp->next))
    if (tmp->type == e_light)
      lights[++pos_lights] = tmp;
  lights[++pos_lights] = NULL;
  return (lights);
}
