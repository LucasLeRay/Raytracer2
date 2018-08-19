/*
** op_coef_diffuse.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 15:22:40 2017 Guts
** Last update Sun May 28 21:46:51 2017 Thery Fouchter
*/

#include "raytracer.h"

int	op_coef_diffuse(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;

  cpy = my_strdup(&s[13]);
  if ((check_syntax_coef(cpy, s, line_n)) == -1)
    return (-1);
  parsing->objects->coef_diffuse = my_atof(cpy);
  free(cpy);
  return (0);
}
