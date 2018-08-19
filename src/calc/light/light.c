/*
** light.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 15:40:22 2017 Thery Fouchter
** Last update Wed Mar 22 15:52:36 2017 Thery Fouchter
*/

#include "raytracer.h"

float		get_light_coef(sfVector3f light_vector,
			       sfVector3f normal_vector)
{
  float		coef;

  light_vector = v_nrm(light_vector);
  normal_vector = v_nrm(normal_vector);
  coef = v_dot(light_vector, normal_vector);
  if (coef <= 0)
    coef = 0;
  else if (coef >= 1)
    coef = 1;
  return (coef);
}
