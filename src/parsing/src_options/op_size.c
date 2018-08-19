/*
** op_pos.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 14:07:00 2017 Guts
** Last update Fri May 26 17:58:08 2017 Guts
*/

#include "raytracer.h"

int	op_size(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;
  int	i;
  int	mem;

  i = -1;
  mem = 0;
  cpy = my_strdup(&s[5]);
  if ((check_syntax_pos(cpy, s, line_n)) == -1)
    return (-1);
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->size.x = my_atof(&cpy[mem]);
  mem = i + 1;
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->size.y = my_atof(&cpy[mem]);
  mem = i + 1;
  parsing->objects->size.z = my_atof(&cpy[mem]);
  free(cpy);
  return (0);
}
