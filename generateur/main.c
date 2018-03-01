/*
** main.c for h in /home/sebag/Bureau/dante/creation
**
** Made by Sebag
** Login   <sebag_f@epitech.net>
**
** Started on  Tue May 10 14:58:09 2016 Sebag
** Last update Sun May 29 19:44:08 2016 Florent Sebag
*/

#include <stdio.h>
#include "generator.h"

int		my_strcmp(char *src, char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != src[i])
	return (0);
      i = i + 1;
    }
  if (src[i] != '\0')
    return (0);
  return (1);
}

void		my_put_err(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i = i + 1;
    }
}

void		parsor_generator(char **av, int ac)
{
  int		i;
  int		j;

  i = atoi(av[1]);
  j = atoi(av[2]);
  if (i < 2 || j < 3)
    {
      my_put_err("Error arguments not possible\n");
      return ;
    }
  if (ac == 3)
    {
      create_maze(i, j, 1);
      return ;
    }
  if (my_strcmp(av[3], "parfait") == 1)
    create_maze(i, j, 0);
  if (my_strcmp(av[3], "[parfait]") == 1)
    create_maze(i, j, 0);
}

int		main(int ac, char **av)
{
  if (ac < 3)
    {
      my_put_err("[ERROR] : Expected [./creator] [longeur] [hauteur] [type]\n");
      return (-1);
    }
  parsor_generator(av, ac);
  return (0);
}
