/*
** cone.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 15:30:13 2017 Thery Fouchter
** Last update Thu May 25 22:57:13 2017 Thery Fouchter
*/

#include "raytracer.h"

static float	calc_cone_delta(float semiangle,
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
  float		t;

  v.x = 0;
  v.y = 0;
  v.z = 1;
  semiangle = tan(semiangle);
  t = 1 + (semiangle * semiangle);
  dot_dv = v_dot(dir, v);
  dot_ov = v_dot(ori, v);
  a = v_dot(dir, dir) - (t * dot_dv * dot_dv);
  b = 2 * (v_dot(dir, ori) - (t * dot_dv * dot_ov));
  c = v_dot(ori, ori) - (t * dot_ov * dot_ov);
  eq->x = a;
  eq->y = b;
  eq->z = c;
  return ((b * b) - (4 * a * c));
}

float		intersect_cone(sfVector3f eye_pos,
			       sfVector3f dir_vector,
			       float semiangle)
{
  sfVector3f	eq;
  float		d;
  float		k1;
  float		k2;

  d = calc_cone_delta(semiangle, eye_pos, dir_vector, &eq);
  if (d < 0)
    return (-1.0);
  if (!d)
    k1 = -eq.y / (2 * eq.x);
  else
    {
      k1 = (-eq.y + (d = sqrt(d))) / (eq.x = eq.x * 2);
      k2 = (-eq.y - d) / eq.x;
      if (k1 <= 0 && k2 <= 0)
	return (-1.0);
      else if (!(k1 > 0 && k2 <= 0) && ((k1 <= 0 && k2 > 0)
					|| (k1 > 0 && k2 > 0 && k1 > k2)))
	k1 = k2;
    }
  return (k1 <= 0 ? -1.0 : k1);
}

sfVector3f	get_normal_cone(sfVector3f intersection_point,
				float semiangle)
{
  semiangle = 1 / semiangle;
  intersection_point.z *= -semiangle;
  return (intersection_point);
}
