/*
** op_texture.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 15:45:27 2017 Guts
** Last update Wed May 24 18:36:39 2017 Thery Fouchter
*/

#include "raytracer.h"

int		fill_cube_mapping(t_parsing *parsing, char *cpy,
				  char *s, int line_n)
{
  if ((parsing->objects->texture = malloc(sizeof(t_ppm_texture) * 7)) == NULL)
    return (-1);
  parsing->objects->texture[0] = read_PPM(my_strcat(cpy, "posx.ppm", '/'));
  parsing->objects->texture[1] = read_PPM(my_strcat(cpy, "negx.ppm", '/'));
  parsing->objects->texture[2] = read_PPM(my_strcat(cpy, "negy.ppm", '/'));
  parsing->objects->texture[3] = read_PPM(my_strcat(cpy, "posy.ppm", '/'));
  parsing->objects->texture[4] = read_PPM(my_strcat(cpy, "posz.ppm", '/'));
  parsing->objects->texture[5] = read_PPM(my_strcat(cpy, "negz.ppm", '/'));
  parsing->objects->texture[6] = NULL;
  free(cpy);
  if (parsing->objects->texture[0] == NULL
      || parsing->objects->texture[1] == NULL
      || parsing->objects->texture[2] == NULL
      || parsing->objects->texture[3] == NULL
      || parsing->objects->texture[4] == NULL
      || parsing->objects->texture[5] == NULL)
    return (print_error_syntax(line_n, s));
  return (0);
}

int		op_texture(t_parsing *parsing, char *s, int line_n)
{
  char		*cpy;

  cpy = my_strdup(&s[8]);
  if ((fill_cube_mapping(parsing, cpy, s, line_n)) == -1)
    return (-1);
  return (0);
}
