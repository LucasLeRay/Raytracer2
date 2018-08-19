/*
** chess.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Wed May 24 21:32:55 2017 Thery Fouchter
** Last update Sat May 27 17:25:35 2017 Thery Fouchter
*/

#include "raytracer.h"

t_objects	*create_chess_choose(sfVector3f pos)
{
  t_objects	*chess;

  if (!(chess = malloc(sizeof(*chess))))
    return (NULL);
  init_node(chess, "chess_choose");
  chess->type = e_plane;
  chess->color = create_color(255, 50, 50, 255);
  chess->pattern_color = create_color(0, 0, 0, 255);
  chess->color_ambient = create_color(255, 255, 255, 255);
  chess->color_diffuse = create_color(255, 255, 255, 255);
  chess->color_specular = create_color(255, 255, 255, 255);
  chess->coef_ambient = 0.1;
  chess->coef_diffuse = 0.3;
  chess->coef_specular = 0.1;
  chess->coef_transparency = 0.85;
  chess->pattern = 192;
  chess->size = create_3vector(20, 20, 20);
  chess->pos = create_3vector(pos.x, pos.y, pos.z - 24);
  return (chess);
}

static int	init_chess_2(t_raytracer *raytracer, t_objects *b)
{
  append_to_obj(b, create_chess_pawn(0, get_chess_pos(b, 0, 1)), 54);
  append_to_obj(b, create_chess_pawn(0, get_chess_pos(b, 1, 1)), 55);
  append_to_obj(b, create_chess_pawn(0, get_chess_pos(b, 2, 1)), 56);
  append_to_obj(b, create_chess_pawn(0, get_chess_pos(b, 3, 1)), 57);
  append_to_obj(b, create_chess_pawn(0, get_chess_pos(b, 4, 1)), 58);
  append_to_obj(b, create_chess_pawn(0, get_chess_pos(b, 5, 1)), 59);
  append_to_obj(b, create_chess_pawn(0, get_chess_pos(b, 6, 1)), 60);
  append_to_obj(b, create_chess_pawn(0, get_chess_pos(b, 7, 1)), 61);
  append_to_obj(b, create_chess_rook(0, get_chess_pos(b, 0, 0)), 63);
  append_to_obj(b, create_chess_knight(0, get_chess_pos(b, 1, 0)), 64);
  append_to_obj(b, create_chess_bishop(0, get_chess_pos(b, 2, 0)), 65);
  append_to_obj(b, create_chess_queen(0, get_chess_pos(b, 3, 0)), 66);
  append_to_obj(b, create_chess_king(0, get_chess_pos(b, 4, 0)), 67);
  append_to_obj(b, create_chess_bishop(0, get_chess_pos(b, 5, 0)), 68);
  append_to_obj(b, create_chess_knight(0, get_chess_pos(b, 6, 0)), 69);
  append_to_obj(b, create_chess_rook(0, get_chess_pos(b, 7, 0)), 70);
  get_chess_piece(b, 63);
  raytracer->chess_choose = create_chess_choose(get_chess_pos(b, 0, 0));
  append_to_obj(raytracer->obj, raytracer->chess_choose, -1);
  return (0);
}

int		init_chess(t_raytracer *raytracer)
{
  t_objects	*b;
  t_objects	*assembly;

  b = create_chess_board(create_3vector(545, 545, -375));
  assembly = ass(b, c3v(500, 500, 500), c3v(545, 545, -375));
  append_to_obj(raytracer->obj, assembly, -1);
  raytracer->chess_board = b;
  append_to_obj(b, create_chess_rook(1, get_chess_pos(b, 0, 7)), 0);
  append_to_obj(b, create_chess_knight(1, get_chess_pos(b, 1, 7)), 1);
  append_to_obj(b, create_chess_bishop(1, get_chess_pos(b, 2, 7)), 2);
  append_to_obj(b, create_chess_queen(1, get_chess_pos(b, 3, 7)), 3);
  append_to_obj(b, create_chess_king(1, get_chess_pos(b, 4, 7)), 4);
  append_to_obj(b, create_chess_bishop(1, get_chess_pos(b, 5, 7)), 5);
  append_to_obj(b, create_chess_knight(1, get_chess_pos(b, 6, 7)), 6);
  append_to_obj(b, create_chess_rook(1, get_chess_pos(b, 7, 7)), 7);
  append_to_obj(b, create_chess_pawn(1, get_chess_pos(b, 0, 6)), 9);
  append_to_obj(b, create_chess_pawn(1, get_chess_pos(b, 1, 6)), 10);
  append_to_obj(b, create_chess_pawn(1, get_chess_pos(b, 2, 6)), 11);
  append_to_obj(b, create_chess_pawn(1, get_chess_pos(b, 3, 6)), 12);
  append_to_obj(b, create_chess_pawn(1, get_chess_pos(b, 4, 6)), 13);
  append_to_obj(b, create_chess_pawn(1, get_chess_pos(b, 5, 6)), 14);
  append_to_obj(b, create_chess_pawn(1, get_chess_pos(b, 6, 6)), 15);
  append_to_obj(b, create_chess_pawn(1, get_chess_pos(b, 7, 6)), 16);
  return (init_chess_2(raytracer, b));
}
