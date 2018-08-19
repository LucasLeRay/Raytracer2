/*
** open_file.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed Apr 26 14:00:49 2017 Guts
** Last update Mon May  1 16:53:36 2017 Thery
*/

#include "raytracer.h"

int	open_file(char *file)
{
  int	fd;

  if ((fd = open(file, O_RDONLY, S_IRUSR)) == -1)
    my_printf("%sYour file: %s is invalid.%s\n", RED, file, RESET);
  return (fd);
}
