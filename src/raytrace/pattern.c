/*
** pattern.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Tue Apr 25 13:27:44 2017 Thery Fouchter
** Last update Sat May 27 17:09:22 2017 Thery Fouchter
*/

#include "raytracer.h"

/*
** Patterns :			| Cools patterns :
** - 1  : squares (positives)	| - 3  : checkboard
** - 2  : squares (negatives)	| - 7  : striped check
** - 4  : circle (positives)	| - 42 : squares land
** - 8  : circle (negatives)	| - 48 : max lit. sqr.
** - 16 : vertical lines
** - 32 : horizontal lines
** - 64 : perlin noises
*/

int	surface_pattern(float x, float y, int pat)
{
  int	x_and2;
  int	y_and2;
  int	x_mod2;
  int	y_mod2;
  int	xy_mod2;

  y_mod2 = (x_mod2 = (xy_mod2 = (x_and2 = (y_and2 = 0))));
  x_and2 = (pat & 1 || pat & 2 ? ((int)x / 10) & 2 : x_and2);
  y_and2 = (pat & 1 || pat & 2 ? ((int)y / 10) & 2 : y_and2);
  xy_mod2 = (pat & 4 || pat & 8 ? (int)(x + y) % 2 : xy_mod2);
  x_mod2 = (pat & 16  || pat & 32 ? (int)x % 2 : x_mod2);
  y_mod2 = (pat & 16  || pat & 32 ? (int)y % 2 : y_mod2);
  x_and2 = (pat & 64 || pat & 128 ? ((int)x / 45) & 2 : x_and2);
  y_and2 = (pat & 64 || pat & 128 ? ((int)y / 45) & 2 : y_and2);
  return ((pat & 1 && (x_and2 && y_and2)) || (pat & 2 && (!x_and2 && !y_and2))
	  || (pat & 64 && (x_and2 && y_and2))
	  || (pat & 128 && (!x_and2 && !y_and2))
	  || (pat & 4 && xy_mod2) || (pat & 8 && !xy_mod2)
	  || (pat & 16 && x_mod2) || (pat & 32 && y_mod2));
}

int	surface_pattern_xy(sfVector3f hit, int pat)
{
  return (surface_pattern(hit.x, hit.y, pat));
}

int	surface_pattern_xz(sfVector3f hit, int pat)
{
  return (surface_pattern(hit.x, hit.z, pat));
}

int	surface_pattern_yz(sfVector3f hit, int pat)
{
  return (surface_pattern(hit.y, hit.z, pat));
}

sfColor		apply_pattern_color(sfColor color, sfColor pattern_color,
				    sfVector3f pos, int pattern)
{
  if (surface_pattern_xy(pos, pattern))
    {
      if (pattern_color.r != 1 || pattern_color.g != 1
	  || pattern_color.b != 1)
	return (pattern_color);
      return (mult_color(color, 0.5));
    }
  return (color);
}
