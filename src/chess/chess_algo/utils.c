/*
** utils.c for emacs in /home/Olivier/Echec
** 
** Made by Olivier Telouk
** Login   <Olivier@epitech.net>
** 
** Started on  Thu May 25 08:01:01 2017 Olivier Telouk
** Last update Sun May 28 21:34:30 2017 Thery Fouchter
*/

#include "raytracer.h"

int	ret(char *s)
{
  int	return_value;

  return_value = write(2, s, my_strlen(s));
  return_value = return_value;
  return (1);
}

void	aff_list(t_case *list)
{
  t_case *tmp;

  tmp = list;
  my_printf("List :\n\n");
  while (tmp)
    {
      my_printf("%d ", tmp->place);
      tmp = tmp->next;
    }
  my_printf("\n");
}

int	is_in_list(t_case *list, int place)
{
  t_case *tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->place == place)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

void	aff_map(char *map, int mouse, t_case *list)
{
  int	count;

  count = -1;
  while (map[++count])
    {
      if (count == mouse)
	my_putchar('O');
      else if (is_in_list(list, count))
	my_putchar('X');
      else
	my_putchar(map[count]);
    }
}
