/*
** moves.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Tue May 23 23:09:46 2017 Olivier Telouk
** Last update Thu May 25 19:03:00 2017 Thery Fouchter
*/

#include "raytracer.h"

t_piece	*get_piece_name(t_all *all, int place)
{
  t_piece *tmp;

  all->turn ? (tmp = all->black) : (tmp = all->white);
  while (tmp && tmp->place != place)
    tmp = tmp->next;
  return (tmp);
}

int	check_taken(t_piece *piece, int place)
{
  t_piece *tmp;

  tmp = piece;
  while (tmp && tmp->place != place)
    tmp = tmp->next;
  return (tmp == NULL ? 1 : 0);
}

int	get_normal_move(t_all *all, t_case **list, t_piece *piece)
{
  t_piece *tmp;
  t_piece *tmp2;
  t_case *tmp3;

  tmp2 = piece;
  tmp3 = tmp2->cases;
  all->turn ? (tmp = all->black) : (tmp = all->white);
  while (tmp3)
    {
      if (check_taken(tmp, tmp3->place))
	if (add_case(list, tmp3->place))
	  return (1);
      tmp3 = tmp3->next;
    }
  return (0);
}

int	get_piece_move(t_all *all, t_piece **list, int place, int indic)
{
  t_piece *piece;
  t_piece *tmp;

  tmp = *list;
  if ((piece = get_piece_name(all, place)) == NULL)
    return (0);
  if (piece->name == BISHOP || piece->name == KNIGHT ||
      piece->name == ROOK || piece->name == QUEEN || piece->name == KING)
    {
      if (get_normal_move(all, &tmp->cases, piece))
	return (1);
    }
  else if (piece->name == PAWN)
    {
      if (get_pawn_move(all, &tmp->cases, piece))
	return (1);
    }
  if (indic && piece->name == KING)
    {
      if (get_castle(all, &tmp->cases, piece))
	return (1);
    }
  return (0);
}
