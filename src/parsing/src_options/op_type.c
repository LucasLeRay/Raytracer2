/*
** op_type.c for raytracer2 in /home/guts/Projects/thery/raytracer2/src/parsing/src_options
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Sat May  6 16:56:44 2017 Guts
** Last update Sat May 27 14:13:29 2017 Guts
*/

#include "raytracer.h"

char	**fill_array_type(void)
{
  char	**array_type;

  array_type = malloc(sizeof(char*) * 16);
  array_type[0] = my_strdup("sphere");
  array_type[1] = my_strdup("cone");
  array_type[2] = my_strdup("cylinder");
  array_type[3] = my_strdup("plane");
  array_type[4] = my_strdup("miter");
  array_type[5] = my_strdup("moebius");
  array_type[6] = my_strdup("pyramid");
  array_type[7] = my_strdup("light");
  array_type[8] = my_strdup("hyperbole");
  array_type[9] = my_strdup("paraboloide");
  array_type[10] = my_strdup("blackhole");
  array_type[11] = my_strdup("bohemian");
  array_type[12] = my_strdup("chubs");
  array_type[13] = my_strdup("void_cube");
  array_type[14] = my_strdup("devil");
  array_type[15] = NULL;
  return (array_type);
}

int	find_type_object(char *cpy, char *s, int line_n)
{
  char	**array_type;
  int	i;

  i = -1;
  array_type = fill_array_type();
  while (array_type[++i])
    if (my_strcmp(cpy, array_type[i]) == 1)
      return (i + 1);
  return (print_error_syntax(line_n, s));
}

int	op_type(t_parsing *parsing, char *s, int line_n)
{
  char	*cpy;
  int	n;

  cpy = my_strdup(&s[5]);
  if ((n = find_type_object(cpy, s, line_n)) == -1)
    return (-1);
  parsing->objects->type = n;
  return (0);
}
