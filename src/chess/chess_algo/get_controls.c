/*
** get_controls.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Tue May 23 05:28:28 2017 Olivier Telouk
** Last update Thu May 25 19:03:58 2017 Thery Fouchter
*/

#include "raytracer.h"

int	add_case(t_case **cases, int place)
{
  t_case *new;

  if ((new = malloc(sizeof(t_case))) == NULL)
    return (1);
  new->place = place;
  new->next = *cases;
  *cases = new;
  return (0);
}

int	get_limit_case(int place, int add, char *map, t_case **cases)
{
  int	indic;
  int	value;

  indic = 1;
  value = place + add;
  while ((indic) && value <= END && value >= START && map[value] != '\n')
    {
      map[value] != ' ' ? (indic = 0) : (indic = 1);
      if (add_case(cases, value))
	return (1);
      value = value + add;
    }
  return (0);
}

int	get_case(int place, t_case **cases, char *map)
{
  if (place >= START && place <= END && map[place] != '\n')
    if (add_case(cases, place))
      return (1);
  return (0);
}

int	get_controls(t_piece **piece, char *map)
{
  t_piece *tmp;
  int ret;

  ret = 0;
  tmp = *piece;
  while (tmp != NULL)
    {
      if (tmp->name == PAWN)
	ret = control_pawn(&tmp, map);
      else if (tmp->name == BISHOP)
	ret = control_bishop(&tmp, map);
      else if (tmp->name == KNIGHT)
	ret = control_knight(&tmp, map);
      else if (tmp->name == QUEEN)
	ret = control_queen(&tmp, map);
      else if (tmp->name == KING)
	ret = control_king(&tmp, map);
      else if (tmp->name == ROOK)
	ret = control_rook(&tmp, map);
      if (ret)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}
