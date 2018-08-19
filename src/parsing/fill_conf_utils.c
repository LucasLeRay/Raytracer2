/*
** fill_conf_utils.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Sun May 28 22:00:26 2017 Thery Fouchter
** Last update Sun May 28 22:00:42 2017 Thery Fouchter
*/

#include "raytracer.h"

void	memset_parsing(t_parsing *parsing)
{
  parsing->music = NULL;
  parsing->wallpaper = NULL;
  parsing->wallpaper_ppm = NULL;
  parsing->render_distance = 0;
  parsing->max_recursion = 0;
  parsing->line_calc = 0;
  parsing->objects = NULL;
}

int	fill_music(t_parsing *parsing, char *music_file,
		   int line_n, char *line)
{
  if ((parsing->music = sfMusic_createFromFile(music_file)) == NULL)
    {
      my_printf("%sError at line %d:\n%s\nINVALID MUSIC.%s\n",
		RED, line_n, line, RESET);
      return (-1);
    }
  return (0);
}

int		fill_wallpaper(t_parsing *parsing, char *file,
			       int line_n, char *line)
{
  t_ppm_texture	*texture;
  int		fd;

  if ((fd = open(file, O_RDONLY)) == -1 || !(texture = read_PPM(file)))
    {
      my_printf("%sError at line %d:\n%s\nINVALID IMAGE.%s\n",
		RED, line_n, line, RESET);
      return (-1);
    }
  close(fd);
  parsing->wallpaper = my_strcpy(file);
  parsing->wallpaper_ppm = texture;
  return (0);
}

int	fill_rendering(t_parsing *parsing, char *file, int line_n,
		       char *line)
{
  if ((parsing->rendering = my_atoi(file)) <= 0)
    {
      my_printf("%sError at line %d:\n%s\nINVALID RENDERING.%s\n",
		RED, line_n, line, RESET);
      return (-1);
    }
  return (0);
}
