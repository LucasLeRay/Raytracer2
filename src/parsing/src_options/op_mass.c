/*
** op_mass.c for raytracer2 in /home/guts/Projects/MUL_2016/open_bmp/raytracer2/src/parsing/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed May 24 14:39:23 2017 Guts
** Last update Wed May 24 14:41:56 2017 Guts
*/

#include "raytracer.h"

int	op_mass(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;

  cpy = my_strdup(&s[5]);
  if (check_syntax_effects(cpy, s, line_n) == -1)
    return (-1);
  parsing->objects->mass = my_atoi(cpy);
  free(cpy);
  return (0);
}
