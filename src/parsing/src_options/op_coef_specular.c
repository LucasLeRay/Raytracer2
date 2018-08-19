/*
** op_coef_specular.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 15:24:23 2017 Guts
** Last update Fri May 26 17:58:27 2017 Guts
*/

#include "raytracer.h"

int	op_coef_specular(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;

  cpy = my_strdup(&s[14]);
  if ((check_syntax_coef(cpy, s, line_n)) == -1)
    return (-1);
  parsing->objects->coef_specular = my_atof(cpy);
  free(cpy);
  return (0);
}
