/*
** op_pattern.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 15:45:46 2017 Guts
** Last update Fri May 26 17:51:59 2017 Guts
*/

#include "raytracer.h"

int	op_pattern(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;

  cpy = my_strdup(&s[8]);
  if (check_syntax_effects(cpy, s, line_n) == -1)
    return (-1);
  parsing->objects->pattern = my_atoi(cpy);
  free(cpy);
  return (0);
}
