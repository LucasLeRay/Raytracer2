/*
** chess_board.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Wed May 24 21:35:07 2017 Thery Fouchter
** Last update Sat May 27 17:17:31 2017 Thery Fouchter
*/

#include "raytracer.h"

t_objects	*create_chess_board(sfVector3f pos)
{
  t_objects	*chess;

  if (!(chess = malloc(sizeof(*chess))))
    return (NULL);
  init_node(chess, "chess_board");
  chess->type = e_plane;
  chess->color = create_color(255, 255, 255, 255);
  chess->pattern_color = create_color(0, 0, 0, 255);
  chess->color_ambient = create_color(255, 255, 255, 255);
  chess->color_diffuse = create_color(255, 255, 255, 255);
  chess->color_specular = create_color(255, 255, 255, 255);
  chess->coef_ambient = 0.1;
  chess->coef_diffuse = 0.3;
  chess->coef_specular = 0.1;
  chess->coef_reflexion = 0.7;
  chess->coef_refraction = 0.8;
  chess->coef_transparency = 0.65;
  chess->pattern = 192;
  chess->size = create_3vector(350, 355, 350);
  chess->pos = create_3vector(pos.x, pos.y, pos.z);
  return (chess);
}
