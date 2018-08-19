/*
** board.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Tue May 23 04:02:14 2017 Olivier Telouk
** Last update Fri May 26 12:37:25 2017 Olivier Telouk
*/

#include "raytracer.h"

char	*clean_map(char *map)
{
  int	a;

  a = -1;
  while (map[++a])
    if (map[a] != '\n')
      map[a] = ' ';
  return (map);
}

void	show_o(t_piece *color)
{
  t_piece *tmp;
  t_case *tmp1;

  tmp = color;
  while (tmp)
    {
      my_printf("\n\n%s -----> %d\n", tmp->desc, tmp->place);
      tmp1 = &tmp->cases[0];
      while (tmp != NULL)
	{
	  my_printf("%d ", tmp1->place);
	  tmp1 = tmp1->next;
	}
      tmp = tmp->next;
    }
  my_printf("\n\n");
}

void	show_all(t_all *all)
{
  t_piece *white;
  t_piece *black;

  white = all->white;
  black = all->black;
  my_printf("White :\n\n");
  show_o(white);
  my_printf("\n\nBlack :\n\n");
  show_o(black);
}

void	put_on_board(t_all **all)
{
  t_all *tmp;
  t_piece *wtmp;
  t_piece *btmp;
  char *map;

  tmp = *all;
  map = tmp->map;
  wtmp = tmp->white;
  btmp = tmp->black;
  while (wtmp != NULL)
    {
      map[wtmp->place] = wtmp->name;
      wtmp = wtmp->next;
    }
  while (btmp != NULL)
    {
      map[btmp->place] = btmp->name;
      btmp = btmp->next;
    }
}
