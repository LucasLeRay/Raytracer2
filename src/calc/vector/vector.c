/*
** vector.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 14:53:25 2017 Thery Fouchter
** Last update Sun May  7 18:26:41 2017 Thery Fouchter
*/

#include "raytracer.h"

float	v_dot(sfVector3f a, sfVector3f b)
{
  return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float	v_len(sfVector3f v)
{
  float	length;

  if ((length = v_dot(v, v)) < 0)
    length = -length;
  return (sqrt(length));
}

sfVector3f	v_nrm(sfVector3f v)
{
  return (v_div_nb(v, v_len(v)));
}

int	v_diff(sfVector3f a, sfVector3f b)
{
  if (a.x == b.x && a.y == b.y && a.z == b.z)
    return (1);
  return (0);
}
