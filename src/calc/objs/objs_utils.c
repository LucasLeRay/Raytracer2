/*
** objs_utils.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 15:55:10 2017 Thery Fouchter
** Last update Wed Mar 22 15:57:20 2017 Thery Fouchter
*/

#include "raytracer.h"

static float	get_smallest_pos(float k1, float k2)
{
  if (k1 < 0 && k2 < 0)
    return (-1.0);
  else if (k1 < 0)
    return (k2);
  else if (k2 < 0)
    return (k1);
  else if (k1 <= k2)
    return (k1);
  else
    return (k2);
}

float		get_delta(float a, float b, float c)
{
  double	d;
  float		k1;
  float		k2;

  d = (b * b) - (4 * a * c);
  if (d > 0)
    {
      if (2 * a == 0)
	return (-1.0);
      k1 = ((-b + sqrt(d)) / (2 * a));
      k2 = ((-b - sqrt(d)) / (2 * a));
      k1 = get_smallest_pos(k1, k2);
      if (k1 <= 0)
	return (-1.0);
      else
	return (k1);
    }
  else if (d == 0)
    {
      if (2 * a == 0)
	return (-1.0);
      k1 = (-b / (2 * a));
      return (k1 <= 0 ? -1.0 : k1);
    }
  return (-1.0);
}
