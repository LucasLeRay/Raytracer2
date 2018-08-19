/*
** op_perlin_freq.c for raytracer2 in /home/guts/Projects/MUL_2016/open_bmp/raytracer2/src/parsing/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed May 24 14:05:31 2017 Guts
** Last update Wed May 24 14:46:31 2017 Guts
*/

#include "raytracer.h"

int	op_perlin_freq(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;

  cpy = my_strdup(&s[12]);
  if ((check_syntax_coef(cpy, s, line_n)) == -1)
    return (-1);
  parsing->objects->perlin_freq = my_atof(cpy);
  free(cpy);
  return (0);
}
