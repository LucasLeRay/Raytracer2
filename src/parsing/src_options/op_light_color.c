/*
** op_light_color.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 15:32:20 2017 Guts
** Last update Fri May 26 17:58:17 2017 Guts
*/

#include "raytracer.h"

int	op_light_color(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;
  int	i;
  int	mem;

  i = -1;
  mem = 0;
  cpy = my_strdup(&s[12]);
  if (find_color(parsing, cpy, &parsing->objects->light_color) == 1)
    return (0);
  if ((check_syntax_color(cpy, s, line_n)) == -1)
    return (-1);
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->light_color.r = my_atoi(&cpy[mem]);
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->light_color.g = my_atoi(&cpy[mem]);
  mem = i + 1;
  parsing->objects->light_color.b = my_atoi(&cpy[mem]);
  free(cpy);
  return (0);
}
