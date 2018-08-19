/*
** principal.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Thu May 25 07:50:34 2017 Olivier Telouk
** Last update Sun May 28 21:35:01 2017 Thery Fouchter
*/

#include "raytracer.h"

int	init_all(t_all **all)
{
  t_all	*tmp;
  t_piece	*white;
  t_piece	*black;

  tmp = *all;
  white = NULL;
  black = NULL;
  if (init_color(&white, &black))
    return (ret("Init failed\n"));
  tmp->white = white;
  tmp->black = black;
  put_on_board(all);
  if (get_controls(&white, tmp->map) ||
      get_controls(&black, tmp->map))
    return (ret("Get controls failed\n"));
  return (0);
}

t_glob	*move_mouse(t_glob *glob, sfEvent *event)
{
  if (event->key.code == KEY_CHESS_RIGHT && glob->mouse + 1 <= END &&
      glob->all->map[glob->mouse + 1] != '\n')
    glob->mouse = glob->mouse + 1;
  if (event->key.code == KEY_CHESS_UP && glob->mouse - ROW >= 0)
    glob->mouse = glob->mouse - ROW;
  if (event->key.code == KEY_CHESS_LEFT && glob->mouse - 1 >= 0 &&
      glob->all->map[glob->mouse - 1] != '\n')
    glob->mouse = glob->mouse - 1;
  if (event->key.code == KEY_CHESS_DOWN && glob->mouse + ROW <= END)
    glob->mouse = glob->mouse + ROW;
  if (!(glob->lock))
    glob->actual = glob->mouse;
  return (glob);
}

t_glob	*exec_event(t_glob *glob, sfEvent *event)
{
  glob = move_mouse(glob, event);
  if (!(glob->lock) && get_piece_move(glob->all, &glob->list, glob->mouse, 1))
    return (NULL);
  if (event->key.code == KEY_CHESS_LOCK)
    {
      glob->send->lock = 1;
      glob->lock ? (glob->lock = 0) : (glob->lock = 1);
    }
  aff_map(glob->all->map, glob->mouse, glob->list->cases);
  if (event->key.code == KEY_CHESS_MOVE)
    glob = exec_move(glob);
  glob->send->cases = glob->list->cases;
  aff_truc(glob->list->cases);
  glob->send->check = is_mate(glob->all);
  glob->send->mouse = glob->mouse;
  aff_send(glob->send);
  if (!(glob->lock))
    {
      free_cases(&glob->list);
      glob->list->cases = NULL;
    }
  my_putchar('\n');
  return (glob);
}

int	init_color(t_piece **white, t_piece **black)
{
  if (init_rook(white, 0) ||
      init_queen(white, 0) ||
      init_knight(white, 0) ||
      init_bishop(white, 0) ||
      init_king(white, 0) ||
      init_pawn(white, 0, 0) ||
      init_rook(black, 1) ||
      init_queen(black, 1) ||
      init_knight(black, 1) ||
      init_bishop(black, 1) ||
      init_king(black, 1) ||
      init_pawn(black, 1, 0))
    return (1);
  return (0);
}
