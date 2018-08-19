/*
** main.c for open_bmp in /home/guts/Projects/MUL_2016/open_bmp
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Mon May 22 16:43:16 2017 Guts
** Last update Sun May 28 21:39:05 2017 Thery Fouchter
*/

#include "raytracer.h"

char	*my_strcat_ppm(char *str, char *str2)
{
  char	*final;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((final = malloc(sizeof(char) *
		      (my_strlen(str) + my_strlen(str2) + 2))) == NULL)
    return (NULL);
  while (str != NULL && str[i])
    {
      final[i] = str[i];
      i++;
    }
  while (str2 != NULL && str2[j])
    {
      final[i] = str2[j];
      i++;
      j++;
    }
  final[i] = 0;
  if (str != NULL)
    free(str);
  return (final);
}

void	check_header(int fd, sfVector2i *size)
{
  char	*header;
  char	buff[3];

  header = NULL;
  read(fd, buff, 3);
  if (buff[0] != 'P' || buff[1] != '6')
    return ;
  my_memset(buff, 3);
  while (read(fd, buff, 1) > 0 && buff[0] == '#')
    while (read(fd, buff, 1) > 0 && buff[0] != '\n');
  header = my_strcat_ppm(header, buff);
  while (read(fd, buff, 1) > 0 && buff[0] != ' ')
    header = my_strcat_ppm(header, buff);
  size->x = my_atoi(header);
  free(header);
  header = NULL;
  while (read(fd, buff, 1) > 0 && buff[0] != '\n')
    header = my_strcat_ppm(header, buff);
  size->y = my_atoi(header);
  free(header);
  while (read(fd, buff, 1) > 0 && buff[0] != '\n');
}

sfColor		**read_image_ppm(t_ppm_texture *texture, int fd)
{
  sfColor	**image;
  int		x;
  int		i;
  int		j;

  i = -1;
  if ((image = malloc(sizeof(sfColor*) * (texture->size.y))) == NULL)
    return (NULL);
  while (++i < texture->size.y)
    {
      j = -1;
      if ((image[i] = malloc(sizeof(sfColor) * (texture->size.x))) == NULL)
	return (NULL);
      while (++j < texture->size.x)
	{
	  read(fd, &x, 1);
	  image[i][j].r = x;
	  read(fd, &x, 1);
	  image[i][j].g = x;
	  read(fd, &x, 1);
	  image[i][j].b = x;
	  image[i][j].a = 255;
	}
    }
  return (image);
}

t_ppm_texture	*read_PPM(char *file)
{
  t_ppm_texture	*texture;
  int		fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((texture = malloc(sizeof(t_ppm_texture))) == NULL)
    return (NULL);
  texture->size.x = -1;
  texture->size.y = -1;
  check_header(fd, &texture->size);
  if (texture->size.x == -1 || texture->size.y == -1)
    return (NULL);
  if ((texture->image = read_image_ppm(texture, fd)) == NULL)
    return (NULL);
  return (texture);
}
