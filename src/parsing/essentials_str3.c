/*
** essentials_str3.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed Apr 26 15:53:57 2017 Guts
** Last update Wed May 24 18:37:40 2017 Thery Fouchter
*/

#include "raytracer.h"

char	*my_strcpy(char *str)
{
  char	*s;
  int	i;

  s = malloc(sizeof(char) * my_strlen(str));
  i = -1;
  while (str[++i])
    s[i] = str[i];
  s[i] = 0;
  return (s);
}
