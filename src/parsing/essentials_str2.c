/*
** essentials_str2.c for PSU_2016_minishell2 in /home/guts/Projects/PSU_2016/PSU_2016_minishell2
** 
** Made by Guts
** Login   <lucas.le-ray@epitech.eu>
** 
** Started on  Wed Mar 29 18:16:09 2017 Guts
** Last update Thu May 25 18:41:19 2017 Thery Fouchter
*/

#include "raytracer.h"

char	*replace_tab_space(char *command)
{
  int	i;

  i = -1;
  while (command[++i])
    if (command[i] == '\t')
      command[i] = ' ';
  return (command);
}

char	*my_strdup(char *str)
{
  char	*s;
  int	i;

  if (str == NULL)
    return (NULL);
  s = malloc(sizeof(char) * my_strlen(str) + 1);
  i = -1;
  while (str[++i])
    s[i] = str[i];
  s[i] = 0;
  return (s);
}

char	*my_strcat(char *begin, char *end, char separator)
{
  int	i;
  int	j;
  char	*final;

  i = -1;
  j = -1;
  final = malloc(sizeof(char) * my_strlen(begin) + my_strlen(end) + 2);
  while (begin[++i])
    final[i] = begin[i];
  if (separator != 0)
    {
      final[i] = separator;
      i++;
    }
  while (end[++j])
    {
      final[i] = end[j];
      i++;
    }
  final[i] = 0;
  return (final);
}

char	*my_strcut(char *str, char separator)
{
  int	i;
  int	j;
  int	pos;
  char	*clear_s;

  i = 0;
  j = 0;
  clear_s = malloc(sizeof(char) * my_strlen(str) + 1);
  while (str[i] == separator)
    i++;
  pos = i;
  i = my_strlen(str) - 1;
  while (str[i] == separator)
    i--;
  str[i + 1] = 0;
  i = pos - 1;
  while (str[++i])
    {
      while (str[i] == separator && str[i - 1] == separator)
	i++;
      clear_s[j] = str[i];
      j++;
    }
  clear_s[j] = 0;
  return (clear_s);
}

int	my_arraylen(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i]);
  return (i);
}
