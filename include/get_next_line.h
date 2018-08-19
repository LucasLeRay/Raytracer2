/*
** get_next_line.h for CPE_2017_getnextline in /home/thery/Bureau/CPE_2017_getnextline
** 
** Made by Thery
** Login   <thery.fouchter@epitech.eu@epitech.net>
** 
** Started on  Mon Jan  2 10:02:55 2017 Thery
** Last update Fri Jan 13 00:15:28 2017 Thery
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# ifndef READ_SIZE
#  define READ_SIZE 20
# endif /* !READ_SIZE */

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_buff
{
  struct s_buff	*next;
  char		buff[READ_SIZE];
  int		data;
  int		total;
}		t_buff;

char	*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
