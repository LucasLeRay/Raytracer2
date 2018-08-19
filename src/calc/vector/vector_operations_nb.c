/*
** vector_operations_nb.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 15:06:36 2017 Thery Fouchter
** Last update Wed Mar 22 15:11:58 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector3f	v_add_nb(sfVector3f a, float b)
{
  a.x += b;
  a.y += b;
  a.z += b;
  return (a);
}

sfVector3f	v_sub_nb(sfVector3f a, float b)
{
  a.x -= b;
  a.y -= b;
  a.z -= b;
  return (a);
}

sfVector3f	v_mult_nb(sfVector3f a, float b)
{
  a.x *= b;
  a.y *= b;
  a.z *= b;
  return (a);
}

sfVector3f	v_div_nb(sfVector3f a, float b)
{
  if (b == 0)
    return (create_null_3vector());
  a.x /= b;
  a.y /= b;
  a.z /= b;
  return (a);
}
