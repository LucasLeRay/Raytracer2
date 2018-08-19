/*
** events_utils.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Thu Mar 23 20:56:58 2017 Thery Fouchter
** Last update Thu Mar 23 20:57:28 2017 Thery Fouchter
*/

#include "raytracer.h"

int	border_int(float *nb, int min, int max, int inc)
{
  int	new;

  if (inc == 0 || (*nb <= min && inc < 0) || (*nb >= max && inc > 0))
    return (0);
  new = *nb + inc;
  if (new <= min)
    new = max - (min - new);
  else if (new >= max)
    new = min + (new - max);
  *nb = new;
  return (1);
}

int	move_eye(t_raytracer *ray, int x, int y, int z)
{
  ray->camera->pos.y -= x;
  ray->camera->pos.x += y;
  ray->camera->pos.z += z;
  return (1);
}

int	change_rot_camera(t_raytracer *ray, int x, int y, int z)
{
  if (!border_int(&ray->camera->rot.x, -360, 360, x)
      && !border_int(&ray->camera->rot.y, -360, 360, y)
      && !border_int(&ray->camera->rot.z, -360, 360, z))
    return (0);
  return (1);
}
