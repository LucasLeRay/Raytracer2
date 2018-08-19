/*
** my_atoi.c for raytracer1 in /home/Cyriack/Projects/MUL_2016/lol/raytracer1/raytracer1/raytracer1
** 
** Made by Lucas Le Ray
** Login   <Cyriack@epitech.net>
** 
** Started on  Sun Mar 19 21:16:48 2017 Lucas Le Ray
** Last update Sun May 28 22:01:42 2017 Thery Fouchter
*/

#include "raytracer.h"

float	my_atof(char *s)
{
  float	value;
  int	i;
  int	dec;
  int	neg;

  i = -1;
  value = 0.0;
  dec = 0;
  neg = 0;
  if (s[0] == '-' && i++)
    neg = 1;
  while (s[++i] && s[i] <= '9' && s[i] >= '0')
    value = value * 10.0 + (s[i] - 48);
  if (s[i] == '.')
    while (s[++i] && s[i] <= '9' && s[i] >= '0')
      {
	value = value * 10.0 + (s[i] - 48);
	dec++;
      }
  while (dec-- > 0)
    value *= 0.1;
  neg == 1 ? (value *= -1) : (value = value);
  return (value);
}

int	my_atoi(char *s)
{
  int	mul;
  int	sign;
  int	i;

  mul = 0;
  sign = 1;
  i = 0;
  if (s == NULL)
    return (0);
  if (s[0] == '-')
    {
      sign *= -1;
      i++;
    }
  while (s[i] && (s[i] >= '0' && s[i] <= '9'))
    {
      mul = (mul * 10) + (s[i] - 48);
      i++;
    }
  mul *= sign;
  return (mul);
}
