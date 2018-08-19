/*
** init_chess.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Thu May 25 18:51:49 2017 Thery Fouchter
** Last update Fri May 26 12:45:36 2017 Olivier Telouk
*/

#include "raytracer.h"

t_glob		*init_chess_game(void)
{
  t_glob	*glob;

  if ((glob = malloc(sizeof(t_glob))) == NULL ||
      (glob->all = malloc(sizeof(t_all))) == NULL ||
      (glob->cpy = malloc(sizeof(t_all))) == NULL ||
      (glob->cpy->map = malloc(sizeof(char) * 73)) == NULL ||
      (glob->list = malloc(sizeof(t_piece))) == NULL ||
      (glob->all->map = get_empty_map()) == NULL)
    return (NULL);
  glob->cpy->map = my_strcpy(glob->all->map);
  if (init_all(&glob->all) || init_all(&glob->cpy))
    return (NULL);
  glob->mouse = 63;
  glob->actual = 63;
  glob->lock = 0;
  glob->list->cases = NULL;
  return (glob);
}

char		*get_empty_map(void)
{
  char		*m;
  int		x;
  int		y;
  int		pos;

  if (!(m = malloc(sizeof(*m) * 73)))
    return (NULL);
  pos = -1;
  y = -1;
  while (++y < 8)
    {
      x = -1;
      while (++x < 8)
	m[++pos] = ' ';
      m[++pos] = '\n';
    }
  m[pos] = 0;
  return (m);
}
