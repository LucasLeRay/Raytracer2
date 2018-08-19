/*
** my_puterr.c for libmy in /home/Cyriack/Projects/lib/my
** 
** Made by Lucas Le Ray
** Login   <Cyriack@epitech.net>
** 
** Started on  Sat Dec 24 15:23:52 2016 Lucas Le Ray
** Last update Sat Dec 24 15:24:18 2016 Lucas Le Ray
*/

void	my_puterr(char c)
{
  write(2, &c, 1);
}
