/*
** assembly.c for  in /home/Thery/Desktop/raytracer2
** 
** Made by Thery Fouchter
** Login   <Thery@epitech.net>
** 
** Started on  Thu May 25 11:35:28 2017 Thery Fouchter
** Last update Thu May 25 12:23:33 2017 Thery Fouchter
*/

#include "raytracer.h"

t_objects	*ass(t_objects *obj, sfVector3f size, sfVector3f pos)
{
  t_objects	*assembly;

  if (!(assembly = malloc(sizeof(*assembly))))
    return (NULL);
  init_node(assembly, "assembly");
  assembly->type = e_sphere;
  assembly->size = size;
  assembly->pos = pos;
  assembly->assembly = obj;
  return (assembly);
}
