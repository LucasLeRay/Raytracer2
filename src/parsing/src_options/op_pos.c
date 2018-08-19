/*
** op_pos.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 14:07:00 2017 Guts
** Last update Fri May 26 17:50:39 2017 Guts
*/

#include "raytracer.h"

int	check_syntax_pos(char *cpy, char *s, int line_n)
{
  int	i;
  int	count;

  i = -1;
  count = 0;
  while (cpy[++i])
    {
      if (cpy[i] == ',')
	count++;
      if ((cpy[i] < '0' || cpy[i] > '9')
	  && cpy[i] != ',' && cpy[i] != '-' && cpy[i] != '.')
	return (print_error_syntax(line_n, s));
    }
  if (count != 2)
    return (print_error_syntax(line_n, s));
  return (0);
}

int	op_pos(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;
  int	i;
  int	mem;

  i = -1;
  mem = 0;
  cpy = my_strdup(&s[4]);
  if ((check_syntax_pos(cpy, s, line_n)) == -1)
    return (-1);
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->pos.x = my_atof(&cpy[mem]);
  mem = i + 1;
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->pos.y = my_atof(&cpy[mem]);
  mem = i + 1;
  parsing->objects->pos.z = my_atof(&cpy[mem]);
  free(cpy);
  return (0);
}
