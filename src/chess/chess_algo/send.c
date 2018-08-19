/*
** send.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Thu May 25 06:55:57 2017 Olivier Telouk
** Last update Thu May 25 18:58:49 2017 Thery Fouchter
*/

#include "raytracer.h"

char	fill_send(int place)
{
  if (place == 2)
    return (8);
  else if (place == 65)
    return (2);
  else if (place == 6)
    return (4);
  else
    return (1);
}

t_send	*init_send(t_send *send)
{
  send = malloc(sizeof(t_send));
  send->check = -1;
  send->cases = NULL;
  send->mouse = 0;
  send->lock = 0;
  send->from = -1;
  send->to = -1;
  send->castle = 0;
  send->moved = 0;
  return (send);
}

void	aff_truc(t_case *cases)
{
  t_case *tmp;

  tmp = cases;
  my_printf("List :\n");
  while (tmp)
    {
      my_printf("%d ", tmp->place);
      tmp = tmp->next;
    }
}

void	aff_send(t_send *send)
{
  my_printf("\n\n\n");
  aff_truc(send->cases);
  my_printf("Check -> %d	Mouse -> %d\n", send->check, send->mouse);
  my_printf("Lock -> %d	Castle -> %d\n", send->lock, send->castle);
  my_printf("Moved -> %d	From -> %d\n", send->moved, send->from);
  my_printf("To -> %d\n\n\n", send->to);
}

