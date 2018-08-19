/*
** my_putchar.c for libmy in /home/Cyriack/Projects/lib/my
** 
** Made by Lucas Le Ray
** Login   <Cyriack@epitech.net>
** 
** Started on  Sat Dec 24 15:22:56 2016 Lucas Le Ray
** Last update Sat Dec 24 15:23:24 2016 Lucas Le Ray
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}
