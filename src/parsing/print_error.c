/*
** print_error.c for raytracer2 in /home/guts/Projects/MUL_2016/raytracer2/parser_Lucas
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Fri Apr 28 13:52:04 2017 Guts
** Last update Mon May  1 16:52:02 2017 Thery
*/

#include "raytracer.h"

int	print_error_syntax(int line_n, char *s)
{
  my_printf("%sError at line %d:\n%s\nINVALID SYNTAX.%s\n",
	    RED, line_n, s, RESET);
  return (-1);
}
