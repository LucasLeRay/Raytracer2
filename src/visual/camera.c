/*
** camera.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 16:10:09 2017 Thery Fouchter
** Last update Wed Mar 22 16:10:27 2017 Thery Fouchter
*/

#include "raytracer.h"

t_camera	*init_camera(t_parser *parser)
{
  t_camera	*camera;

  if (!(camera = malloc(sizeof(*camera))))
    return (NULL);
  camera->pos = parser->cam_pos;
  camera->rot = parser->cam_rot;
  camera->dist_to_plane = parser->cam_dist_to_plane;
  return (camera);
}
