/*
** init_node.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Thu Apr 27 13:10:04 2017 Guts
** Last update Sun May 28 21:58:50 2017 Thery Fouchter
*/

#include "raytracer.h"

void	init_vector_node(t_objects *objects)
{
  objects->pos.x = 0;
  objects->pos.y = 0;
  objects->pos.z = 0;
  objects->speed.x = 0.0;
  objects->speed.y = 0.0;
  objects->speed.z = 0.0;
}

void	init_color_node(t_objects *objects)
{
  objects->color.r = 0;
  objects->color.g = 0;
  objects->color.b = 0;
  objects->color.a = 255;
  objects->color_ambient.r = 0;
  objects->color_ambient.g = 0;
  objects->color_ambient.b = 0;
  objects->color_ambient.a = 255;
  objects->color_diffuse.r = 0;
  objects->color_diffuse.g = 0;
  objects->color_diffuse.b = 0;
  objects->color_diffuse.a = 255;
  objects->color_specular.r = 0;
  objects->color_specular.g = 0;
  objects->color_specular.b = 0;
  objects->color_specular.a = 255;
  objects->pattern_color.r = 1;
  objects->pattern_color.g = 1;
  objects->pattern_color.b = 1;
  objects->pattern_color.a = 255;
}

void	init_coef_light_node(t_objects *objects)
{
  objects->coef_ambient = COEF_AMB;
  objects->coef_diffuse = COEF_DIF;
  objects->coef_specular = COEF_SPE;
  objects->coef_reflexion = COEF_RER;
  objects->coef_refraction = COEF_REX;
  objects->light = LIGHT;
  objects->light_color.r = 0;
  objects->light_color.g = 0;
  objects->light_color.b = 0;
  objects->light_color.a = 255;
  objects->specular_power = 20;
  objects->perlin_noise = 20;
  objects->perlin_freq = 0.0;
  objects->perlin_seed = 1;
}

void	init_node(t_objects *objects, char *s)
{
  objects->next = NULL;
  objects->assembly = NULL;
  objects->inc_pos = create_null_3vector();
  objects->id = -1;
  objects->side = 0;
  objects->name = my_strdup(s);
  objects->effect = EFFECT;
  objects->pattern = PATTERN;
  objects->material = MATERIAL;
  objects->type = DEFAULT_TYPE;
  objects->size.x = SIZE_X;
  objects->size.y = SIZE_Y;
  objects->size.z = SIZE_Z;
  objects->rotation.x = 0.0;
  objects->rotation.y = 0.0;
  objects->rotation.z = 0.0;
  objects->timed_rotation.x = 0.0;
  objects->timed_rotation.y = 0.0;
  objects->timed_rotation.z = 0.0;
  objects->mass = 0;
  objects->check_speed = 0;
  objects->texture = NULL;
  init_vector_node(objects);
  init_color_node(objects);
  init_coef_light_node(objects);
}

t_objects	*insert_node(t_objects *list, char *s)
{
  t_objects	*new_node;

  new_node = malloc(sizeof(t_objects));
  init_node(new_node, s);
  new_node->next = list;
  return (new_node);
}
