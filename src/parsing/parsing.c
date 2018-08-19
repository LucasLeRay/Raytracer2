/*
** parsing.c for  in /home/Thery/Desktop/raytracer2/src
** 
** Made by Thery Fouchter
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 13:43:21 2017 Thery Fouchter
** Last update Sun May 28 14:29:44 2017 Guts
*/

#include "raytracer.h"

int		setup_parsing(t_parser *parser)
{
  t_objects	*tmp;
  t_objects	*prev;
  t_objects	*new;

  if ((tmp = parser->parsing->objects))
    {
      prev = tmp->next;
      while (tmp && (tmp = tmp->next) && tmp && tmp->next)
	prev = tmp;
      if (prev)
	prev->next = NULL;
    }
  if (!(new = malloc(sizeof(*new))))
    return (-1);
  new->next = parser->parsing->objects;
  parser->parsing->objects = new;
  return (0);
}

void		parse_size(t_parser *parser, int ac, char **av)
{
  if (ac == 5 && av[3] != NULL && av[4] != NULL)
    {
      parser->win_x = my_atoi(av[3]);
      parser->win_y = my_atoi(av[4]);
    }
  if (ac < 5 || parser->win_x <= 0 || parser->win_y <= 0)
    {
      parser->win_x = 800;
      parser->win_y = 800;
    }
}

t_parser	*parsing(int ac, char **av)
{
  t_parser	*parser;

  if (ac < 3 || !(parser = malloc(sizeof(*parser)))
      || !(parser->parsing = parse_configuration(av[1], av[2])))
    {
      my_printf("Usage: %s [CONF_FILE] [SETTINGS_FILE] [SIZE_X] [SIZE_Y]\n",
		av[0]);
      return (NULL);
    }
  else if (!parser->parsing->objects)
    return (NULL);
  parse_size(parser, ac, av);
  parser->cam_pos = create_3vector(0, 0, 0);
  parser->cam_rot = create_3vector(0, 0, 0);
  parser->cam_dist_to_plane = 500;
  parser->conf_file = av[1];
  parser->sett_file = av[2];
  if (setup_parsing(parser) == -1)
    return (NULL);
  return (parser);
}
