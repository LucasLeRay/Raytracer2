/*
** clean_line.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed Apr 26 15:32:08 2017 Guts
** Last update Mon May  1 16:52:30 2017 Thery
*/

#include "raytracer.h"

char	*clean_line(char *s)
{
  int	i;

  i = -1;
  if (s == NULL)
    return (NULL);
  while (s[++i] == ' ' || s[i] == '\t');
  return (&s[i]);
}
