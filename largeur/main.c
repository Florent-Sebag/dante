/*
** main.c for h in /home/sebag/Bureau/dante/largeur/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Sun May 22 20:47:43 2016 Florent Sebag
** Last update Sun May 22 23:20:04 2016 Dheilly Joss
*/

#include "solver.h"

t_fir_end	*init_file()
{
  t_fir_end	*file;

  if ((file = malloc(sizeof(t_fir_end))) == NULL)
    exit(EXIT_FAILURE);
  file->size = 0;
  file->first = NULL;
  file->last = NULL;
  return (file);
}

void		init_larg(t_fir_end *list)
{
  t_fir_end 	*file;

  list->first->indic = 1;
  file = init_file();
  if (resolve_larg(list, list->first, file) == -1)
    {
      printf("No solution found\n");
      return ;
    }
  print_res(list);
}

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
      init_larg(list);
      free_linked(list);
    }
  return (0);
}
