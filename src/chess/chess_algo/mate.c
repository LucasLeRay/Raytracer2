/*
** mate.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Thu May 25 03:34:32 2017 Olivier Telouk
** Last update Thu May 25 18:59:25 2017 Thery Fouchter
*/

#include "raytracer.h"

int	get_check_amount(int attack, int kingp)
{
  int	dir;
  int	is_neg;

  dir = attack - kingp;
  dir < 0 ? (is_neg = 1) : (is_neg = 0);
  dir = abs(dir);
  if (dir < 9)
    return (is_neg ? -1 : 1);
  dir = dir % 9;
  if (dir == 0)
    return (is_neg ? - ROW : ROW);
  if (dir >= kingp)
    return (!is_neg ? ROW - 1 : - ROW - 1);
  return (!is_neg ? ROW + 1 : - ROW + 1);
}

int	is_mate(t_all *all)
{
  int	place;

  if ((place = is_king_attacked(all, all->turn, 1)) != 0 &&
      !(can_king_move(all)))
    return (place);
  return (place);
}

int	is_controlled(t_piece *other, int place)
{
  t_piece *tmp;
  t_case *tmp2;

  tmp = other;
  while (tmp != NULL)
    {
      tmp2 = tmp->cases;
      while (tmp2 != NULL)
	{
	  if (tmp2->place == place)
	    return (1);
	  tmp2 = tmp2->next;
	}
      tmp = tmp->next;
    }
  return (0);
}

int	free_glob(t_glob *glob)
{
  full_cases_free(&glob->all);
  full_cases_free(&glob->cpy);
  full_piece_free(&glob->all);
  full_piece_free(&glob->cpy);
  free(glob->all->map);
  free(glob->cpy->map);
  free(glob->all);
  free(glob->cpy);
  free(glob);
  return (0);
}
