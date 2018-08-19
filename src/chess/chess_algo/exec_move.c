/*
** exec_move.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Wed May 24 19:44:58 2017 Olivier Telouk
** Last update Thu May 25 19:05:32 2017 Thery Fouchter
*/

#include "raytracer.h"

int	abs(int nb)
{
  return (nb < 0 ? -nb : nb);
}

t_glob	*change_after_exec(t_glob *glob)
{
  full_cases_free(&glob->all);
  free_cases(&glob->list);
  glob->list->cases = NULL;
  glob->lock = 0;
  glob->send->from = glob->actual;
  glob->send->to = glob->mouse;
  glob->send->moved = 1;
  glob->actual = glob->mouse;
  get_controls(&glob->all->white, glob->all->map);
  get_controls(&glob->all->black, glob->all->map);
  if (is_king_attacked(glob->all, glob->all->turn, 1))
    {
      glob->send->from = -1;
      glob->send->moved = 0;
      glob->send->to = -1;
      copy_all(&glob->all, glob->cpy);
    }
  else
    {
      glob->all->turn ? (glob->all->turn = 0) : (glob->all->turn = 1);
      copy_all(&glob->cpy, glob->all);
    }
  return (glob);
}

t_glob	*exec_move(t_glob *glob)
{
  t_piece *piece;
  char	c;

  if (!(is_in_list(glob->list->cases, glob->mouse)))
    return (glob);
  if (glob->all->map[glob->mouse] != ' ')
    remove_piece(&glob->all, glob->mouse);
  c = glob->all->map[glob->actual];
  glob->all->map[glob->actual] = ' ';
  glob->all->map[glob->mouse] = c;
  piece = get_piece_name(glob->all, glob->actual);
  if (piece->name == KING && abs(glob->mouse - glob->actual) == 2)
    glob = exec_castle(glob, glob->mouse);
  piece->place = glob->mouse;
  return (change_after_exec(glob));
}
