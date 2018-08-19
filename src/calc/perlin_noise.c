/*
** perlin_noise.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Tue May 23 15:04:30 2017 Thery Fouchter
** Last update Sat May 27 16:49:30 2017 Thery Fouchter
*/

#include "raytracer.h"

sfColor		calc_perlin_noise(__attribute__((unused))t_raytracer *raytracer,
				  t_ray *ray, t_objects *obj_hit)
{
  sfVector2f	perlin;
  float		noise;

  if (obj_hit->perlin_freq)
    {
      perlin.x = ray->pos_hit.x;
      perlin.y = MAX(ray->pos_hit.y, ray->pos_hit.z);
      noise = CLAMP(perlin_noise(perlin, obj_hit->perlin_freq,
				 obj_hit->perlin_noise,
				 obj_hit->perlin_seed), -1.0, 1.0);
      if (obj_hit->pattern_color.r != 1 || obj_hit->pattern_color.g != 1
	  || obj_hit->pattern_color.b != 1)
	{
	  if (noise > 0.35)
	    ray->color = mult_color(obj_hit->pattern_color, noise);
	  else
	    ray->color = mult_color(ray->color, noise);
	}
      else
	ray->color = mult_color(ray->color, noise);
    }
  return (ray->color);
}

float		perlin_noise(sfVector2f pos, float freq, int depth, int seed)
{
  float		amp;
  float		fin;
  float		div;
  int		i;

  pos.x *= freq;
  pos.y *= freq;
  amp = 1.0;
  fin = 0.0;
  div = 0.0;
  i = -1;
  while (++i < depth)
    {
      div += 256 * amp;
      fin += noise(pos.x, pos.y, seed) * amp;
      amp /= 2.0;
      pos.x *= 2;
      pos.y *= 2;
    }
  if (!div)
    return (0.0);
  return (fin / div);
}

float		noise(float x, float y, int seed)
{
  float		low;
  float		high;
  float		xf;
  float		yf;
  int		a;
  int		b;

  xf = x - (int)x;
  yf = y - (int)y;
  a = noise_table((int)x, (int)y, seed);
  b = noise_table((int)x + 1, (int)y, seed);
  low = SMOOTH(a, b, xf);
  a = noise_table((int)x, (int)y + 1, seed);
  b = noise_table((int)x + 1, (int)y + 1, seed);
  high = SMOOTH(a, b, xf);
  return (SMOOTH(low, high, yf));
}

int		noise_table(int x, int y, int seed)
{
  static int	t[] = {151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96, 53,
		       194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99,
		       37, 240, 21, 10, 23, 190,  6, 148, 247, 120, 234, 75,
		       0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32,
		       57, 177, 33, 88, 237, 149, 56, 87, 174, 20, 125, 136,
		       171, 168,  68, 175, 74, 165, 71, 134, 139, 48, 27, 166,
		       77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133,
		       230, 220, 105, 92, 41, 55, 46, 245, 40, 244, 102, 143,
		       54,  65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132,
		       187, 208,  89, 18, 169, 200, 196, 135, 130, 116, 188,
		       159, 86, 164, 100, 109, 198, 173, 186,  3, 64, 52, 217,
		       226, 250, 124, 123, 5, 202, 38, 147, 118, 126, 255, 82,
		       85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189,
		       28, 42, 223, 183, 170, 213, 119, 248, 152, 2, 44, 154,
		       163,  70, 221, 153, 101, 155, 167,  43, 172, 9, 129,
		       22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178,
		       185,  112, 104, 218, 246, 97, 228, 251, 34, 242, 193,
		       238, 210, 144, 12, 191, 179, 162, 241,  81, 51, 145,
		       235, 249, 14, 239, 107, 49, 192, 214,  31, 181, 199,
		       106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4,
		       150, 254, 138, 236, 205, 93, 222, 114, 67, 29, 24, 72,
		       243, 141, 128, 195, 78, 66, 215, 61, 156, 180};

  return (t[(t[(y + seed) % 256] + x) % 256]);
}
