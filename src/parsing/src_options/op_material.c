/*
** op_material.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 15:43:32 2017 Guts
** Last update Fri May 26 17:50:23 2017 Guts
*/

#include "raytracer.h"

int	op_material(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;

  cpy = my_strdup(&s[9]);
  if (check_syntax_effects(cpy, s, line_n) == -1)
    return (-1);
  parsing->objects->material = my_atoi(cpy);
  free(cpy);
  return (0);
}
