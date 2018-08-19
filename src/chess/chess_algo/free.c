/*
** free.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Tue May 23 11:15:33 2017 Olivier Telouk
** Last update Thu May 25 18:57:14 2017 Thery Fouchter
*/

#include "raytracer.h"

int	a_remove_piece(t_piece **piece, int place)
{
  t_piece *tmp;
  t_piece *prec;

  tmp = *piece;
  prec = NULL;
  while (tmp && tmp->place != place)
    {
      prec = tmp;
      tmp = tmp->next;
    }
  if (tmp == NULL)
    return (0);
  prec != NULL ? (prec->next = tmp->next) : (*piece = tmp->next);
  free_cases(&tmp);
  free(tmp);
  return (1);
}

int	remove_piece(t_all **all, int place)
{
  t_all	*tmp;
  t_piece	*white;
  t_piece	*black;

  tmp = *all;
  white = tmp->white;
  black = tmp->black;
  if ((a_remove_piece(&white, place)) ||
      (a_remove_piece(&black, place)))
    return (0);
  return (1);
}

void	full_piece_free(t_all **all)
{
  t_all *tmp;
  t_piece *keep;
  t_piece *keep2;

  tmp = *all;
  keep = NULL;
  keep2 = NULL;
  while (tmp->white)
    {
      keep = tmp->white->next;
      free(tmp->white);
      tmp->white = keep;
    }
  while (tmp->black)
    {
      keep2 = tmp->black->next;
      free(tmp->black);
      tmp->black = keep2;
    }
}

void	full_cases_free(t_all **all)
{
  t_all *tmp;
  t_piece *white;
  t_piece *black;

  tmp = *all;
  white = tmp->white;
  black = tmp->black;
  while (white != NULL)
    {
      free_cases(&white);
      white = white->next;
    }
  while (black != NULL)
    {
      free_cases(&black);
      black = black->next;
    }
}

void	free_cases(t_piece **piece)
{
  t_piece *tmp;
  t_case *keep;

  tmp = *piece;
  keep = NULL;
  while (tmp->cases != NULL)
    {
      keep = tmp->cases->next;
      free(tmp->cases);
      tmp->cases = keep;
    }
}
