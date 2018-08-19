/*
** controls.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Tue May 23 04:09:40 2017 Olivier Telouk
** Last update Thu May 25 19:03:18 2017 Thery Fouchter
*/

#include "raytracer.h"

int	control_bishop(t_piece **piece, char *map)
{
  t_piece *tmp;

  tmp = *piece;
  if (get_limit_case(tmp->place, ROW + 1, map, &tmp->cases) ||
      get_limit_case(tmp->place, ROW - 1, map, &tmp->cases) ||
      get_limit_case(tmp->place, -ROW + 1, map, &tmp->cases) ||
      get_limit_case(tmp->place, -ROW - 1, map, &tmp->cases))
    return (1);
  return (0);
}

int	control_king(t_piece **piece, char *map)
{
  t_piece *tmp;

  tmp = *piece;
  if (get_case(tmp->place + ROW, &tmp->cases, map) ||
      get_case(tmp->place + ROW + 1, &tmp->cases, map) ||
      get_case(tmp->place + ROW - 1, &tmp->cases, map) ||
      get_case(tmp->place - ROW, &tmp->cases, map) ||
      get_case(tmp->place - ROW + 1, &tmp->cases, map) ||
      get_case(tmp->place - ROW - 1, &tmp->cases, map) ||
      get_case(tmp->place + 1, &tmp->cases, map) ||
      get_case(tmp->place - 1, &tmp->cases, map))
    return (1);
  return (0);
}

int	control_knight(t_piece **piece, char *map)
{
  int	not_right;
  int	not_left;
  t_piece	*tmp;

  tmp = *piece;
  tmp->place % 9 == 0 ? (not_left = 0) : (not_left = 1);
  tmp->place % 9 == 7 ? (not_right = 0) : (not_right = 1);
  if (get_case(tmp->place + (ROW * 2) + 1, &tmp->cases, map) ||
      get_case(tmp->place + (ROW * 2) - 1, &tmp->cases, map) ||
      (not_right && get_case(tmp->place + ROW + 2, &tmp->cases, map)) ||
      (not_left && get_case(tmp->place + ROW - 2, &tmp->cases, map)) ||
      get_case(tmp->place - (ROW * 2) + 1, &tmp->cases, map) ||
      get_case(tmp->place - (ROW * 2) - 1, &tmp->cases, map) ||
      (not_right && get_case(tmp->place - ROW + 2, &tmp->cases, map)) ||
      (not_left && get_case(tmp->place - ROW - 2, &tmp->cases, map)))
    return (1);
  return (0);
}

int	control_queen(t_piece **piece, char *map)
{
  t_piece *tmp;

  tmp = *piece;
  if (get_limit_case(tmp->place, ROW + 1, map, &tmp->cases) ||
      get_limit_case(tmp->place, ROW - 1, map, &tmp->cases) ||
      get_limit_case(tmp->place, -ROW + 1, map, &tmp->cases) ||
      get_limit_case(tmp->place, -ROW - 1, map, &tmp->cases) ||
      get_limit_case(tmp->place, ROW, map, &tmp->cases) ||
      get_limit_case(tmp->place, -ROW, map, &tmp->cases) ||
      get_limit_case(tmp->place, -1, map, &tmp->cases) ||
      get_limit_case(tmp->place, 1, map, &tmp->cases))
    return (1);
  return (0);
}

int	control_rook(t_piece **piece, char *map)
{
  t_piece *tmp;

  tmp = *piece;
  if (get_limit_case(tmp->place, 1, map, &tmp->cases) ||
      get_limit_case(tmp->place, -1, map, &tmp->cases) ||
      get_limit_case(tmp->place, ROW, map, &tmp->cases) ||
      get_limit_case(tmp->place, -ROW, map, &tmp->cases))
    return (1);
  return (0);
}

