/*
** calc_dir_vector.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Thu Mar 23 19:26:26 2017 Thery Fouchter
** Last update Sat May  6 17:32:21 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size,
				sfVector2i screen_pos)
{
  sfVector3f	dir;

  dir.x = dist_to_plane;
  dir.y = (screen_size.x >> 1) - screen_pos.x;
  dir.z = (screen_size.y >> 1) - screen_pos.y;
  return (dir);
}
