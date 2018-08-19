/*
** music.c for raytracer2 in /home/guts/raytracer2/src/sfml
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Sun May 28 14:05:41 2017 Guts
** Last update Sun May 28 14:16:54 2017 Guts
*/

#include "raytracer.h"

void	init_music(t_raytracer *raytracer)
{
  if (raytracer->parser->parsing->music == NULL)
    return ;
  sfMusic_play(raytracer->parser->parsing->music);
  sfMusic_setLoop(raytracer->parser->parsing->music, 1);
}
