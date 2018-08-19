/*
** pawn.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Tue May 23 05:26:45 2017 Olivier Telouk
** Last update Thu May 25 19:04:48 2017 Thery Fouchter
*/

#include "raytracer.h"

int	init_pawn(t_piece **color, char type, int count)
{
  t_piece	*one;

  if ((one = malloc(sizeof(t_piece))) == NULL)
    return (1);
  one->name = PAWN;
  one->prop = type;
  type == 0 ? (one->place = 54 + count) : (one->place = 9 + count);
  one->cases = NULL;
  one->desc = NAMEP;
  if (count < 7)
    init_pawn(color, type, count + 1);
  one->next = *color;
  *color = one;
  return (0);
}

int	control_pawn(t_piece **piece, char *map)
{
  t_piece	*tmp;

  tmp = *piece;
  if (!(tmp->prop))
    {
      if (get_case(tmp->place - ROW + 1, &tmp->cases, map) ||
	  get_case(tmp->place - ROW - 1, &tmp->cases, map))
	return (1);
    }
  else
    {
      if (get_case(tmp->place + ROW + 1, &tmp->cases, map) ||
	  get_case(tmp->place + ROW - 1, &tmp->cases, map))
	return (1);
    }
  return (0);
}

int	move_pawn_forward(t_all *all, t_piece *piece, t_case **list)
{
  if (piece->prop)
    {
      if (piece->place + ROW <= END &&
	  all->map[piece->place + ROW] == ' ')
	if (add_case(list, piece->place + ROW))
	  return (1);
      if (piece->place >= 9 && piece->place <= 16 &&
	            piece->place + ROW + ROW <= END &&
	  all->map[piece->place + ROW + ROW] == ' ')
	if (add_case(list, piece->place + ROW + ROW))
	  return (1);
    }
  else
    {
      if (piece->place - ROW >= 0 &&
	  all->map[piece->place - ROW] == ' ')
	if (add_case(list, piece->place - ROW))
	  return (1);
      if (piece->place >= 54 && piece->place <= 61 &&
	            piece->place - ROW - ROW >= 0 &&
	  all->map[piece->place - ROW - ROW] == ' ')
	if (add_case(list, piece->place - ROW - ROW))
	  return (1);
    }
  return (0);
}

int	get_pawn_move(t_all *all, t_case **list, t_piece *piece)
{
  t_piece *tmp;
  t_piece *tmp2;
  t_case *tmp3;

  tmp2 = piece;
  tmp3 = tmp2->cases;
  all->turn ? (tmp = all->white) : (tmp = all->black);
  while (tmp3)
    {
      if (!(check_taken(tmp, tmp3->place)))
	if (add_case(list, tmp3->place))
	  return (1);
      tmp3 = tmp3->next;
    }
  return (move_pawn_forward(all, piece, list));
}
