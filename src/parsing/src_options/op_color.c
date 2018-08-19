/*
** op_color.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 14:33:18 2017 Guts
** Last update Fri May 26 17:51:28 2017 Guts
*/

#include "raytracer.h"

int	check_syntax_color(char *cpy, char *s, int line_n)
{
  int	i;
  int	count;

  i = -1;
  count = 0;
  while (cpy[++i])
    {
      if (cpy[i] == ',')
	count++;
      if ((cpy[i] < '0' || cpy[i] > '9') && cpy[i] != ',')
	return (print_error_syntax(line_n, s));
    }
  if (count != 2)
    return (print_error_syntax(line_n, s));
  return (0);
}

int	find_color(t_parsing *parsing, char *cpy, sfColor *color)
{
  parsing = parsing;
  if (my_strcmp(cpy, "red") == 1
      || my_strcmp(cpy, "purple") == 1
      || my_strcmp(cpy, "orange") == 1
      || my_strcmp(cpy, "white") == 1)
    (*color).r = 255;
  if (my_strcmp(cpy, "green") == 1
      || my_strcmp(cpy, "orange") == 1
      || my_strcmp(cpy, "cyan") == 1
      || my_strcmp(cpy, "white") == 1)
    (*color).g = 255;
  if (my_strcmp(cpy, "blue") == 1
      || my_strcmp(cpy, "purple") == 1
      || my_strcmp(cpy, "cyan") == 1
      || my_strcmp(cpy, "white") == 1)
    (*color).b = 255;
  if (my_strcmp(cpy, "blue") == 1
      || my_strcmp(cpy, "green") == 1
      || my_strcmp(cpy, "red") == 1
      || my_strcmp(cpy, "orange") == 1
      || my_strcmp(cpy, "cyan") == 1
      || my_strcmp(cpy, "purple") == 1
      || my_strcmp(cpy, "black") == 1 || my_strcmp(cpy, "white") == 1)
    return (1);
  return (0);
}

int	op_color(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;
  int	i;
  int	mem;

  i = -1;
  mem = 0;
  cpy = my_strdup(&s[6]);
  if (find_color(parsing, cpy, &parsing->objects->color) == 1)
    return (0);
  if ((check_syntax_color(cpy, s, line_n)) == -1)
    return (-1);
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->color.r = my_atoi(&cpy[mem]);
  mem = i + 1;
  while (cpy[++i] && cpy[i] != ',');
  if (cpy[i] == ',')
    parsing->objects->color.g = my_atoi(&cpy[mem]);
  mem = i + 1;
  parsing->objects->color.b = my_atoi(&cpy[mem]);
  free(cpy);
  return (0);
}
