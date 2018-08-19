/*
** op_effect.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 15:37:22 2017 Guts
** Last update Fri May 26 17:50:30 2017 Guts
*/

#include "raytracer.h"

int	check_syntax_effects(char *cpy, char *s, int line_n)
{
  int	i;

  i = -1;
  while (cpy[++i])
    if (cpy[i] < '0' || cpy[i] > '9')
      return (print_error_syntax(line_n, s));
  return (0);
}

int	op_effect(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;

  cpy = my_strdup(&s[7]);
  if (check_syntax_effects(cpy, s, line_n) == -1)
    return (-1);
  parsing->objects->effect = my_atoi(cpy);
  free(cpy);
  return (0);
}
