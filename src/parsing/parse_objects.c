/*
** parse_objects.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 13:39:08 2017 Guts
** Last update Mon May  1 16:53:48 2017 Thery
*/

#include "raytracer.h"

int	fill_line_object(t_parsing *parsing, char *s, char **options_list,
			 PARAMS options)
{
  int	i;

  i = -1;
  s = clean_line(s);
  while (options_list[++i])
    if (my_strncmp(s, options_list[i], my_strlen(options_list[i])) == 1)
      return (options[i](parsing, s, parsing->line_n));
  my_printf("%sError at line %d:\n%s\nINVALID OPTION.%s\n",
	    RED, parsing->line_n, s, RESET);
  return (-1);
}

int	parse_objects(t_parsing *parsing, int fd, char **options_list,
		      PARAMS options)
{
  char	*s;

  s = get_next_line(fd);
  if (s[0] != '{')
    return (print_error_syntax(parsing->line_n, s));
  parsing->line_n++;
  while ((s = get_next_line(fd)) && s[0] != '}')
    {
      if (fill_line_object(parsing, s, options_list, options) == -1)
	return (-1);
      parsing->line_n++;
    }
  if (s == NULL)
    return (print_error_syntax(parsing->line_n, s));
  parsing->line_n++;
  return (parsing->line_n);
}
