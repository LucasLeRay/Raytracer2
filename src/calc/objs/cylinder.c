/*
** cylinder.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 15:28:35 2017 Thery Fouchter
** Last update Sat May 27 16:42:37 2017 Thery Fouchter
*/

#include "raytracer.h"

static float	calc_cylinder_delta(float radius,
				    sfVector3f ori,
				    sfVector3f dir,
				    sfVector3f *eq)
{
  sfVector3f	v;
  float		a;
  float		b;
  float		c;
  float		dot_dv;
  float		dot_ov;

  v.x = 0;
  v.y = 0;
  v.z = 1;
  dot_dv = v_dot(dir, v);
  dot_ov = v_dot(ori, v);
  a = v_dot(dir, dir) - (dot_dv * dot_dv);
  b = 2 * (v_dot(dir, ori) - (dot_dv * dot_ov));
  c = v_dot(ori, ori) - (dot_ov * dot_ov) - (radius * radius);
  eq->x = a;
  eq->y = b;
  eq->z = c;
  return ((b * b) - (4 * a * c));
}

float		intersect_cylinder(sfVector3f eye_pos,
				   sfVector3f dir_vector,
				   float radius)
{
  sfVector3f	eq;
  sfVector2f	k;
  float		d;
  float		k1;
  float		k2;

  d = calc_cylinder_delta(radius, eye_pos, dir_vector, &eq);
  if (d < 0)
    return (-1.0);
  if (!d)
    k.x = -eq.y / (2 * eq.x);
  else
    {
      k1 = (-eq.y + (d = sqrt(d))) / (eq.x = eq.x * 2);
      k2 = (-eq.y - d) / eq.x;
      k.x = k1;
      if (k1 <= 0 && k2 <= 0)
	return (-1.0);
      else if (!(k1 > 0 && k2 <= 0) && ((k1 <= 0 && k2 > 0)
					|| (k1 > 0 && k2 > 0 && k1 > k2)))
	k.x = k2;
      k.y = (k.x == k2 ? k1 : k2);
    }
  return (k.x <= 0 ? -1.0 : k.x);
}

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  intersection_point.z = 0;
  return (intersection_point);
}
