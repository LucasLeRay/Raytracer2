/*
** fill_quality.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed Apr 26 15:10:36 2017 Guts
** Last update Sun May 28 22:06:40 2017 Thery Fouchter
*/

#include "raytracer.h"

static int	fill_line_quality_2(t_parsing *parsing, char *s, int line_n)
{
  if (my_strncmp(s, "line_calc=", 10) == 1)
    if ((parsing->line_calc = my_atoi(&s[10])) <= 0)
      {
	my_printf("%sError at line %d:\n%s\nINVALID VALUE.%s\n",
		  RED, line_n, s, RESET);
	return (-1);
      }
  if (my_strncmp(s, "antialiasing=", 13) == 1)
    if ((parsing->antialiasing = my_atoi(&s[13])) < 0)
      {
	my_printf("%sError at line %d:\n%s\nINVALID VALUE.%s\n",
		  RED, line_n, s, RESET);
	return (-1);
      }
  if (my_strncmp(s, "line_calc=", 10) == 0
      && my_strncmp(s, "max_recursion=", 14) == 0
      && my_strncmp(s, "render_distance=", 16) == 0
      && my_strncmp(s, "antialiasing=", 13) == 0)
    {
      my_printf("%sError at line %d:\n%s\nINVALID OPTION.%s\n",
		RED, line_n, s, RESET);
      return (-1);
    }
  return (0);
}

int	fill_line_quality(t_parsing *parsing, char *s, int line_n)
{
  s = clean_line(s);
  if (my_strncmp(s, "render_distance=", 16) == 1)
    if ((parsing->render_distance = my_atoi(&s[16])) <= 0)
      {
	my_printf("%sError at line %d:\n%s\nINVALID VALUE.%s\n",
		  RED, line_n, s, RESET);
	return (-1);
      }
  if (my_strncmp(s, "max_recursion=", 14) == 1)
    if ((parsing->max_recursion = my_atoi(&s[14])) <= 0)
      {
	my_printf("%sError at line %d:\n%s\nINVALID VALUE.%s\n",
		  RED, line_n, s, RESET);
	return (-1);
      }
  if (fill_line_quality_2(parsing, s, line_n) == -1)
    return (-1);
  return (0);
}

int	quality_found(t_parsing *parsing, int fd, int line_n)
{
  char	*s;

  s = get_next_line(fd);
  if (s[0] != '{')
    {
      my_printf("%sError at line %d:\n%s\nINVALID SYNTAX.%s\n",
		RED, line_n, s, RESET);
      return (-1);
    }
  line_n++;
  while ((s = get_next_line(fd)) && s[0] != '}')
    {
      if ((fill_line_quality(parsing, s, line_n)) == -1)
	return (-1);
      line_n++;
      free(s);
    }
  if (s == NULL)
    {
      my_printf("%sError at line %d:\n%s\nINVALID SYNTAX.%s\n",
		RED, line_n, s, RESET);
      return (-1);
    }
  return (0);
}

int	fill_quality(t_parsing *parsing, int fd, int line_n, char *line)
{
  char	*quality;
  int	line_nset;
  char	*s;
  
  quality = &line[8];
  line_nset = 1;
  parsing->render_distance = 200;
  parsing->max_recursion = 1;
  parsing->line_calc = 2;
  parsing->antialiasing = 0;
  while ((s = get_next_line(fd)))
    {
      if (my_strcmp(s, quality) == 1)
	{
	  if ((quality_found(parsing, fd, line_nset)) == -1)
	    return (-1);
	  else
	    return (0);
	}
      free(s);
      line_nset++;
    }
  my_printf("%sError at line %d:\n%s\tINVALID QUALITY.%s\n",
	    RED, line_n, line, RESET);
  return (-1);
}
