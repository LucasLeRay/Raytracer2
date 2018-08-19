/*
** op_timed_rotation.c for raytracer2 in /home/guts/Projects/MUL_2016/open_bmp/raytracer2/src/parsing/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed May 24 14:34:30 2017 Guts
** Last update Wed May 24 14:48:03 2017 Guts
*/

#include "raytracer.h"

int	op_timed_rotation(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;
  int	i;
  int	mem;

  i = -1;
  mem = 0;
  cpy = my_strdup(&s[15]);
  if ((check_syntax_pos(cpy, s, line_n)) == -1)
    return (-1);
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->timed_rotation.x = my_atof(&cpy[mem]);
  mem = i + 1;
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->timed_rotation.y = my_atof(&cpy[mem]);
  mem = i + 1;
  parsing->objects->timed_rotation.z = my_atof(&cpy[mem]);
  free(cpy);
  return (0);
}
