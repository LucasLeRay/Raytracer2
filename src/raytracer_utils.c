/*
** raytracer_utils.c<src> for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Fri May  5 18:25:01 2017 Thery Fouchter
** Last update Thu May 25 23:24:51 2017 Thery Fouchter
*/

#include "raytracer.h"

int	init_raytracer(t_raytracer *raytracer)
{
  if (!(raytracer->visual = init_visual(raytracer->parser))
      || !(raytracer->camera = init_camera(raytracer->parser))
      || !(raytracer->obj = raytracer->parser->parsing->objects)
      || !(raytracer->lights = get_lights(raytracer->obj)))
    return (-1);
  reset_raytracer(raytracer);
  raytracer->play_chess = 0;
  raytracer->chess_board = NULL;
  raytracer->chess_choose = NULL;
  if (my_strcmp(raytracer->parser->conf_file, "ressources/chess.conf")
      && (raytracer->glob = init_chess_game()))
    {
      raytracer->play_chess = 1;
      init_chess(raytracer);
    }
  return (0);
}

int	reset_raytracer(t_raytracer *ray)
{
  ray->camera->pos = ray->parser->cam_pos;
  ray->camera->rot = ray->parser->cam_rot;
  ray->camera->dist_to_plane = ray->parser->cam_dist_to_plane;
  ray->opti = 1;
  return (1);
}
