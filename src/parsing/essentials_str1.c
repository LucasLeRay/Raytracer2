/*
** essentials_str1.c for PSU_2016_minishell2 in /home/guts/Delivery/PSU_2016_minishell2
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Sun Mar 26 17:55:10 2017 Guts
** Last update Mon May  1 16:52:34 2017 Thery
*/

#include "raytracer.h"

void	my_memset(char *str, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    str[i] = 0;
}

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i]);
  return (i);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = -1;
  if (my_strlen(str1) != my_strlen(str2))
    return (0);
  while (str1[++i])
    if (str1[i] != str2[i])
      return (0);
  return (1);
}

int	my_strncmp(char *str1, char *str2, int n)
{
  int	i;

  i = -1;
  while (str1[++i] && str2[i] && i <= n)
    if (str1[i] != str2[i])
      return (0);
  return (1);
}

char	**my_str_to_wordtab(char *str, char separator)
{
  char	**tab;
  int	jump;
  int	i;
  int	j;

  i = -1;
  j = 0;
  jump = 1;
  while (str[++i])
    str[i] == separator ? jump++ : 42;
  tab = malloc(sizeof(char*) * jump + 16);
  i = -1;
  jump = 0;
  while (str[++i])
    if (str[i] == separator)
      {
	str[i] = 0;
	tab[jump] = &str[j];
	j = i + 1;
	jump++;
      }
  tab[jump] = &str[j];
  tab[jump + 1] = NULL;
  return (tab);
}
