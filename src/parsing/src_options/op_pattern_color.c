/*
** op_pattern_color.c for raytracer2 in /home/guts/Projects/MUL_2016/open_bmp/raytracer2/src/parsing/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed May 24 14:10:28 2017 Guts
** Last update Wed May 24 14:47:48 2017 Guts
*/

#include "raytracer.h"

int	op_pattern_color(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;
  int	i;
  int	mem;

  i = -1;
  mem = 0;
  cpy = my_strdup(&s[14]);
  if (find_color(parsing, cpy, &parsing->objects->pattern_color) == 1)
    return (0);
  if ((check_syntax_color(cpy, s, line_n)) == -1)
    return (-1);
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->pattern_color.r = my_atoi(&cpy[mem]);
  mem = i + 1;
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->pattern_color.g = my_atoi(&cpy[mem]);
  mem = i + 1;
  parsing->objects->color.b = my_atoi(&cpy[mem]);
  free(cpy);
  return (0);
}
