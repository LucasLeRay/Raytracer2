/*
** color.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Thu Mar 23 20:24:39 2017 Thery Fouchter
** Last update Wed May 24 19:49:39 2017 Thery Fouchter
*/

#include "raytracer.h"

sfColor		mult_color(sfColor color, float coef)
{
  color.r *= coef;
  color.g *= coef;
  color.b *= coef;
  color.r = CLAMP(color.r, 0.0, 255.0);
  color.g = CLAMP(color.g, 0.0, 255.0);
  color.b = CLAMP(color.b, 0.0, 255.0);
  return (color);
}

sfColor		mix_color(sfColor a, float coef_a, sfColor b, float coef_b)
{
  a.r = a.r * coef_a + b.r * coef_b;
  a.g = a.g * coef_a + b.g * coef_b;
  a.b = a.b * coef_a + b.b * coef_b;
  return (a);
}

sfColor		create_color(int r, int g, int b, int a)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}
