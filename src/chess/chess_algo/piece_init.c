/*
** piece_init.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Tue May 23 03:14:57 2017 Olivier Telouk
** Last update Thu May 25 19:02:08 2017 Thery Fouchter
*/

#include "raytracer.h"

int	init_bishop(t_piece **color, char type)
{
  t_piece	*one;
  t_piece	*two;

  if ((one = malloc(sizeof(t_piece))) == NULL ||
      (two = malloc(sizeof(t_piece))) == NULL)
    return (1);
  one->name = BISHOP;
  one->prop = type;
  type == 0 ? (one->place = 65) : (one->place = 2);
  one->cases = NULL;
  one->desc = NAMEB;
  one->next = *color;
  *color = one;
  two->name = BISHOP;
  type == 0 ? (two->place = 68) : (two->place = 5);
  two->cases = NULL;
  two->prop = type;
  two->desc = NAMEB;
  two->next = *color;
  *color = two;
  return (0);
}

int	init_rook(t_piece **color, char type)
{
  t_piece	*one;
  t_piece	*two;

  if ((one = malloc(sizeof(t_piece))) == NULL ||
      (two = malloc(sizeof(t_piece))) == NULL)
    return (1);
  one->name = ROOK;
  one->prop = type;
  type == 0 ? (one->place = 63) : (one->place = 0);
  one->cases = NULL;
  one->next = NULL;
  one->desc = NAMER;
  *color = one;
  two->name = ROOK;
  type == 0 ? (two->place = 70) : (two->place = 7);
  two->prop = type;
  two->cases = NULL;
  two->desc = NAMER;
  two->next = *color;
  *color = two;
  return (0);
}

int	init_queen(t_piece **color, char type)
{
  t_piece	*one;

  if ((one = malloc(sizeof(t_piece))) == NULL)
    return (1);
  one->name = QUEEN;
  one->prop = type;
  type == 0 ? (one->place = 66) : (one->place = 3);
  one->cases = NULL;
  one->desc = NAMEQ;
  one->next = *color;
  *color = one;
  return (0);
}

int	init_king(t_piece **color, char type)
{
  t_piece	*one;

  if ((one = malloc(sizeof(t_piece))) == NULL)
    return (1);
  one->prop = type;
  one->name = KING;
  type == 0 ? (one->place = 67) : (one->place = 4);
  one->cases = NULL;
  one->desc = NAMEK;
  one->next = *color;
  *color = one;
  return (0);
}

int	init_knight(t_piece **color, char type)
{
  t_piece	*one;
  t_piece	*two;

  if ((one = malloc(sizeof(t_piece))) == NULL ||
      (two = malloc(sizeof(t_piece))) == NULL)
    return (1);
  one->prop = type;
  one->name = KNIGHT;
  type == 0 ? (one->place = 64) : (one->place = 1);
  one->cases = NULL;
  one->desc = NAMEN;
  one->next = *color;
  *color = one;
  two->name = KNIGHT;
  type == 0 ? (two->place = 69) : (two->place = 6);
  two->cases = NULL;
  two->prop = type;
  two->desc = NAMEN;
  two->next = *color;
  *color = two;
  return (0);
}
