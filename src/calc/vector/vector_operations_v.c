/*
** vector_operations.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 15:01:15 2017 Thery Fouchter
** Last update Wed Mar 22 15:10:04 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector3f	v_add_v(sfVector3f a, sfVector3f b)
{
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return (a);
}

sfVector3f	v_sub_v(sfVector3f a, sfVector3f b)
{
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return (a);
}

sfVector3f	v_mult_v(sfVector3f a, sfVector3f b)
{
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return (a);
}

sfVector3f	v_div_v(sfVector3f a, sfVector3f b)
{
  a.x = (!b.x ? 0 : a.x / b.x);
  a.y = (!b.y ? 0 : a.y / b.y);
  a.z = (!b.z ? 0 : a.z / b.z);
  return (a);
}
