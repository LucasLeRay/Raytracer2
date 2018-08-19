/*
** op_inherit.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 18:14:34 2017 Guts
** Last update Fri May 26 17:56:33 2017 Guts
*/

#include "raytracer.h"

void		fill_inherit2(t_objects *obj, t_objects *mem)
{
  obj->pattern_color = mem->pattern_color;
  obj->material = mem->material;
  obj->texture = mem->texture;
  obj->type = mem->type;
  obj->size = mem->size;
  obj->rotation = mem->rotation;
  obj->timed_rotation = mem->timed_rotation;
  obj->mass = mem->mass;
}

int		fill_inherit1(t_objects *obj, t_objects *mem)
{
  obj->pos = mem->pos;
  obj->color = mem->color;
  obj->color_ambient = mem->color_ambient;
  obj->color_diffuse = mem->color_diffuse;
  obj->color_specular = mem->color_specular;
  obj->light_color = mem->light_color;
  obj->effect = mem->effect;
  obj->pattern = mem->pattern;
  obj->material = mem->material;
  obj->light = mem->light;
  obj->coef_ambient = mem->coef_ambient;
  obj->coef_diffuse = mem->coef_diffuse;
  obj->coef_specular = mem->coef_specular;
  obj->coef_transparency = mem->coef_transparency;
  obj->coef_reflexion = mem->coef_reflexion;
  obj->coef_refraction = mem->coef_refraction;
  obj->specular_power = mem->specular_power;
  obj->perlin_noise = mem->perlin_noise;
  obj->perlin_freq = mem->perlin_freq;
  obj->perlin_seed = mem->perlin_seed;
  obj->effect = mem->effect;
  obj->pattern = mem->pattern;
  fill_inherit2(obj, mem);
  return (0);
}

int		op_inherit(t_parsing *parsing, char *s, int line_n)
{
  char		*cpy;
  t_objects	*mem;

  cpy = my_strdup(&s[8]);
  mem = parsing->objects;
  while (mem)
    {
      if (my_strcmp(cpy, mem->name) == 1)
	return (fill_inherit1(parsing->objects, mem));
      mem = mem->next;
    }
  my_printf("%sError at line %d:\n%s\nINVALID NAME OF OBJ.\n%s",
	    RED, line_n, s, RESET);
  return (-1);
}
