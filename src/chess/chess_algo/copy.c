/*
** copy.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Tue May 23 23:44:18 2017 Olivier Telouk
** Last update Fri May 26 12:45:27 2017 Olivier Telouk
*/

#include "raytracer.h"

int	a_piece_copy(t_piece **color, t_piece *old)
{
  t_piece	*new;

  if ((new = malloc(sizeof(t_piece))) == NULL)
    return (1);
  new->name = old->name;
  new->prop = old->prop;
  new->place = old->place;
  new->desc = old->desc;
  color != NULL ? (new->next = *color) : (new->next = NULL);
  new->cases = NULL;
  *color = new;
  return (0);
}

int	piece_copy(t_piece **copy, t_piece *piece)
{
  t_piece *tmp;

  tmp = piece;
  while (tmp)
    {
      if ((a_piece_copy(copy, tmp)))
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int	full_piece_copy(t_all **new, t_all *old)
{
  t_all *tmp;
  t_piece *white;
  t_piece *black;

  tmp = *new;
  white = old->white;
  black = old->black;
  if (piece_copy(&tmp->white, white)
      || piece_copy(&tmp->black, black))
    return (1);
  return (0);
}

int	copy_all(t_all **copied, t_all *old)
{
  t_all	*tmp;

  tmp = *copied;
  free(tmp->map);
  full_cases_free(&tmp);
  full_piece_free(&tmp);
  free(tmp);
  if ((tmp = malloc(sizeof(t_all))) == NULL ||
      (tmp->map = malloc(sizeof(char) * 73)) == NULL)
    return (1);
  tmp->map = my_strcpy(old->map);
  if (full_piece_copy(&tmp, old) ||
      get_controls(&tmp->white, tmp->map) ||
      get_controls(&tmp->black, tmp->map))
    return (1);
  tmp->check = old->check;
  tmp->check = old->turn;
  return (0);
}
