/*
** get_next_line.c for CPE_2017_getnextline in /home/thery/Bureau/CPE_2017_getnextline
** 
** Made by Thery
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Mon Jan  2 09:58:57 2017 Thery
** Last update Mon Jan 30 19:25:39 2017 Thery Fouchter
*/

#include "get_next_line.h"

static char	*get_str_from_buff(t_buff *b, int size_read)
{
  t_buff	*tmp;
  char		*str;
  int		pos_str;
  int		i;

  pos_str = 0;
  if ((size_read <= 0 && !b->total)
      || (str = malloc(sizeof(char) * (b->total + 1))) == NULL)
    return (NULL);
  tmp = b;
  while (tmp)
    {
      i = -1;
      while (++i < tmp->data)
	str[pos_str++] = tmp->buff[i];
      b = (tmp == b ? NULL : tmp);
      tmp = tmp->next;
      if (b)
	free(b);
    }
  if (tmp)
    free(tmp);
  str[pos_str++] = 0;
  return (str);
}

static t_buff	*append_char(t_buff *ori, t_buff *l, char c)
{
  t_buff	*new;

  if (l->data >= READ_SIZE)
    {
      if ((new = malloc(sizeof(*new))) == NULL)
	return (l);
      l->next = new;
      new->data = 0;
      new->next = NULL;
      return (append_char(ori, new, c));
    }
  l->buff[l->data++] = c;
  ori->total += 1;
  return (l);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE];
  static int	size_read;
  static int	pos = -1;
  t_buff	b;
  t_buff	*l;

  b.next = NULL;
  b.data = 0;
  b.total = 0;
  l = &b;
  while (42)
    {
      if (pos < 0)
	if ((size_read = read(fd, buff, READ_SIZE)) <= 0)
	  return (get_str_from_buff(&b, size_read));
      while (++pos < size_read && buff[pos] != '\n')
	buff[pos] != '\n' ? (l = append_char(&b, l, buff[pos])) : 0;
      if (pos >= size_read)
	pos = -1;
      else
	return (get_str_from_buff(&b, size_read));
    }
}
