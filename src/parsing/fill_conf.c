/*
** fill_conf.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed Apr 26 14:30:40 2017 Guts
** Last update Sun May 28 22:00:40 2017 Thery Fouchter
*/

#include "raytracer.h"

int	fill_conf_parsing(t_parsing *parsing, char *s, int line)
{
  if (my_strncmp(s, "MUSIC=", 6) == 1)
    if ((fill_music(parsing, &s[6], line, s)) == -1)
      return (-1);
  if (my_strncmp(s, "WALLPAPER=", 10) == 1)
    if ((fill_wallpaper(parsing, &s[10], line, s)) == -1)
      return (-1);
  if (my_strncmp(s, "RENDERING=", 10) == 1)
    if ((fill_rendering(parsing, &s[10], line, s)) == -1)
      return (-1);
  return (0);
}

int	fill_conf(t_parsing *parsing, int fd_conf, int fd_sett)
{
  char	*s;
  int	line;
  int	check;

  line = 1;
  check = 0;
  memset_parsing(parsing);
  while ((s = get_next_line(fd_conf)) && s[0] != '\0')
    {
      if ((fill_conf_parsing(parsing, s, line)) == -1)
	return (-1);
      if (my_strncmp(s, "QUALITY=", 8) == 1)
	{
	  if ((fill_quality(parsing, fd_sett, line, s)) == -1)
	    return (-1);
	  check++;
	}
      free(s);
      line++;
    }
  if (check == 0)
    if ((fill_quality(parsing, fd_sett, -1, "QUALITY=NONE")) == -1)
      return (-1);
  return (0);
}
