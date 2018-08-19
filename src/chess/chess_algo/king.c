/*
** king.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Tue May 23 11:27:25 2017 Olivier Telouk
** Last update Thu May 25 19:05:16 2017 Thery Fouchter
*/

#include "raytracer.h"

int	can_king_move(t_all *all)
{
  t_piece *list;
  t_piece *piece;
  t_piece *other;

  list = malloc(sizeof(t_piece));
  list->cases = malloc(sizeof(t_case));
  list->cases = NULL;
  all->turn ? (piece = all->black) : (piece = all->white);
  all->turn ? (other = all->white) : (other = all->black);
  while (piece && piece->name != KING)
    piece = piece->next;
  get_piece_move(all, &list, piece->place, 0);
  while (list->cases != NULL && is_controlled(other, list->cases->place))
    list->cases = list->cases->next;
  if (list->cases == NULL)
    {
      my_printf("OMG JE PEUX PLUS BOUGER\n");
      return (0);
    }
  free_cases(&list);
  return (1);
}

int	is_king_attacked(t_all *all, int prop, int indic)
{
  t_piece *tmp;
  t_piece *tmp2;
  t_case *tmp3;

  !(prop) ? (tmp = all->white) : (tmp = all->black);
  !(prop) ? (tmp2 = all->black) : (tmp2 = all->white);
  while (tmp && tmp->name != KING)
    tmp = tmp->next;
  while (tmp2)
    {
      tmp3 = tmp2->cases;
      while (tmp3)
	{
	  if (tmp3->place == tmp->place)
	    return (!(indic) ? 1 : tmp2->place);
	  tmp3 = tmp3->next;
	}
      tmp2 = tmp2->next;
    }
  return (0);
}

int	get_castle(t_all *all, t_case **list, t_piece *piece)
{
  if (piece->prop && piece->place == 4)
    {
      if (all->map[5] == ' ' && all->map[6] == ' ' && all->map[7] == 'R')
	if (add_case(list, 6))
	  return (1);
      if (all->map[3] == ' ' && all->map[2] == ' ' && all->map[1] == ' ' &&
	  all->map[0] == 'R')
	if (add_case(list, 2))
	  return (1);
    }
  else if (!(piece->prop) && piece->place == 67)
    {
      if (all->map[68] == ' ' && all->map[69] == ' ' && all->map[70] == 'R')
	if (add_case(list, 69))
	  return (1);
      if (all->map[66] == ' ' && all->map[65] == ' ' && all->map[64] == ' ' &&
	  all->map[63] == 'R')
	if (add_case(list, 65))
	  return (1);
    }
  return (0);
}

t_glob	*move_rook_castle(t_glob *glob, int dest, int rookplace)
{
  t_piece *piece;

  glob->all->map[rookplace] = ' ';
  glob->all->map[dest] = 'R';
  piece = get_piece_name(glob->all, rookplace);
  piece->place = dest;
  return (glob);
}

t_glob	*exec_castle(t_glob *glob, int place)
{
  int dest;
  int rookplace;

  if (place == 69)
    {
      dest = 68;
      rookplace = 70;
    }
  if (place == 6)
    {
      dest = 5;
      rookplace = 7;
    }
  if (place == 65)
    {
      dest = 66;
      rookplace = 63;
    }
  if (place == 2)
    {
      dest = 3;
      rookplace = 0;
    }
  glob->send->castle = fill_send(place);
  return (move_rook_castle(glob, dest, rookplace));
}
