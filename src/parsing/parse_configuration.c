/*
** parse_configuration.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed Apr 26 13:52:04 2017 Guts
** Last update Sun May 28 22:02:12 2017 Thery Fouchter
*/

#include "raytracer.h"

t_objects	*init_list(void)
{
  t_objects	*list;

  list = malloc(sizeof(t_objects));
  init_node(list, NULL);
  return (list);
}

t_parsing	*parse_configuration(char *file_conf, char *file_sett)
{
  int		fd_conf;
  int		fd_sett;
  t_parsing	*parsing;

  if ((fd_conf = open_file(file_conf)) == -1)
    return (NULL);
  if ((fd_sett = open_file(file_sett)) == -1)
    return (NULL);
  parsing = malloc(sizeof(t_parsing));
  parsing->rendering = -1;
  if ((fill_conf(parsing, fd_conf, fd_sett)) == -1)
    return (NULL);
  parsing->objects = init_list();
  close(fd_conf);
  close(fd_sett);
  if ((fd_conf = open_file(file_conf)) == -1)
    return (NULL);
  if (fill_objects(parsing, fd_conf) == -1)
    return (NULL);
  return (parsing);
}
