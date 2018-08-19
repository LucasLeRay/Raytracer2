/*
** chess_move.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Thu May 25 22:27:43 2017 Thery Fouchter
** Last update Thu May 25 22:28:35 2017 Thery Fouchter
*/

#include "raytracer.h"

int		move_assembly(t_objects *ass, sfVector3f pos, int new_id)
{
  t_objects	*tmp;

  if ((tmp = ass))
    {
      tmp->pos = create_3vector(pos.x, pos.y, pos.z + 25);
      tmp->id = new_id;
      tmp = tmp->assembly;
    }
  while (tmp)
    {
      tmp->pos = v_add_v(pos, tmp->inc_pos);
      tmp = tmp->next;
    }
  return (0);
}

int		move_chess_piece(t_objects *b, t_objects *choose,
				 int from, int to)
{
  t_objects	*tmp;
  t_objects	*prev;
  sfVector3f	new;
  int		moved[2];

  if (b)
    new = get_chess_pos(b, to % 9, 7 - to / 9);
  if (choose)
    choose->pos = create_3vector(new.x, new.y, choose->pos.z);
  moved[0] = 0;
  moved[1] = 0;
  tmp = b;
  prev = b;
  while (tmp && to != -1 && from != -1)
    {
      if (!moved[0] && tmp->id == to && (moved[0] = 1))
	prev->next = tmp->next;
      if (!moved[1] && tmp->id == from && (moved[1] = 1))
	move_assembly(tmp, new, to);
      prev = tmp;
      tmp = tmp->next;
    }
  return (0);
}

t_objects	*get_chess_piece(t_objects *b, int id)
{
  t_objects	*tmp;
  t_objects	*piece;
  t_objects	*found;

  found = NULL;
  tmp = b;
  while (tmp)
    {
      if ((piece = get_chess_piece(tmp->assembly, id)))
	found = piece;
      else if (tmp->id == id)
	found = tmp;
      if (found && (piece = found->assembly))
	{
	  while (piece)
	    {
	      set_objcolor_side(piece, 2);
	      piece = piece->next;
	    }
	}
      set_objcolor_side(tmp, tmp->side);
      tmp = tmp->next;
    }
  return (found);
}
