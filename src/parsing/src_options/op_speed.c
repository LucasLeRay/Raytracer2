/*
** op_speed.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/src/parsing/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Thu May 25 19:44:05 2017 Guts
** Last update Fri May 26 00:16:25 2017 Guts
*/

#include "raytracer.h"

int	op_speed(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;
  int	i;
  int	mem;

  i = -1;
  mem = 0;
  cpy = my_strdup(&s[6]);
  if ((check_syntax_pos(cpy, s, line_n)) == -1)
    return (-1);
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->speed.x = my_atof(&cpy[mem]);
  mem = i + 1;
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->speed.y = my_atof(&cpy[mem]);
  mem = i + 1;
  parsing->objects->speed.z = my_atof(&cpy[mem]);
  parsing->objects->check_speed = 1;
  free(cpy);
  return (0);
}
