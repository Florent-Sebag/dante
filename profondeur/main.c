/*
** main.c for h in /home/sebag/Bureau/dante/largeur/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Sun May 22 20:47:43 2016 Florent Sebag
** Last update Sun May 29 19:58:01 2016 Dheilly Joss
*/

#include "solver.h"

int		main(int ac, char **av)
{
  int		fd;
  t_fir_end	*list;

  if (ac > 1)
    {
      if ((fd = open(av[1], O_RDONLY)) == -1)
	return (-1);
      if ((list = get_maze(fd)) == NULL)
	return (-1);
      close(fd);
      if (list->last->data != '*')
	return (-1);
      init_prof(list);
    }
  return (0);
}
