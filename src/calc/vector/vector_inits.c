/*
** vector_inits.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 15:07:37 2017 Thery Fouchter
** Last update Thu May 25 11:34:18 2017 Thery Fouchter
*/

#include "raytracer.h"

sfVector2f	create_2vector(float x, float y)
{
  sfVector2f	v;

  v.x = x;
  v.y = y;
  return (v);
}

sfVector3f	c3v(float x, float y, float z)
{
  return (create_3vector(x, y, z));
}

sfVector3f	create_3vector(float x, float y, float z)
{
  sfVector3f	v;

  v.x = x;
  v.y = y;
  v.z = z;
  return (v);
}

sfVector3f	create_null_3vector(void)
{
  return (create_3vector(0, 0, 0));
}
