/*
** main.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Tue May 23 02:49:28 2017 Olivier Telouk
** Last update Fri May 26 12:45:17 2017 Olivier Telouk
*/

#include "raytracer.h"

int	main(int ac, char **av)
{
  t_glob *glob;
  int a;
  int b;

  if ((glob = malloc(sizeof(t_glob))) == NULL ||
      (glob->all = malloc(sizeof(t_all))) == NULL ||
      (glob->all->map = malloc(sizeof(char) * 73)) == NULL ||
      (glob->cpy = malloc(sizeof(t_all))) == NULL ||
      (glob->cpy->map = malloc(sizeof(char) * 73)) == NULL ||
      (glob->list = malloc(sizeof(t_piece))) == NULL)
    return (1);
  a = open("map", O_RDONLY);
  b = read(a, glob->all->map, 72);
  glob->all->map[b] = 0;
  glob->cpy->map = my_strcpy(glob->all->map);
  if (init_all(&glob->all) || init_all(&glob->cpy))
    return (1);
  glob->mouse = 63;
  glob->actual = 63;
  glob->lock = 0;
  glob->list->cases = NULL;
  do_stuff(glob);
  return (0);
}
