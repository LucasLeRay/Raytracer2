/*
** plane.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 15:37:42 2017 Thery Fouchter
** Last update Wed Mar 22 15:38:58 2017 Thery Fouchter
*/

#include "raytracer.h"

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float k;

  if (dir_vector.z == 0 && -eye_pos.z < 0)
    k = -3000000;
  else if (dir_vector.z == 0 && -eye_pos.z > 0)
    k = 3000000;
  else if (dir_vector.z == 0 && eye_pos.z == 0)
    k = 0;
  else
    k = -eye_pos.z / dir_vector.z;
  if (k < 0)
    return (-1.0);
  return (k);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	n;

  n.x = 0;
  n.y = 0;
  n.z = (upward ? 100 : -100);
  return (n);
}
