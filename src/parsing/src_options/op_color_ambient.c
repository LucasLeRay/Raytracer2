/*
** op_color_ambient.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 14:53:05 2017 Guts
** Last update Fri May 26 17:57:42 2017 Guts
*/

#include "raytracer.h"

int	op_color_ambient(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;
  int	i;
  int	mem;

  i = -1;
  mem = 0;
  cpy = my_strdup(&s[14]);
  if (find_color(parsing, cpy, &parsing->objects->color_ambient) == 1)
    return (0);
  if ((check_syntax_color(cpy, s, line_n)) == -1)
    return (-1);
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->color_ambient.r = my_atoi(&cpy[mem]);
  mem = i + 1;
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->color_ambient.g = my_atoi(&cpy[mem]);
  mem = i + 1;
  parsing->objects->color_ambient.b = my_atoi(&cpy[mem]);
  free(cpy);
  return (0);
}
