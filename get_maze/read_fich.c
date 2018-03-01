/*
** read_fich.c for h in /home/sebag/Bureau/dante/creation/recup/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Wed May 11 19:02:30 2016 Florent Sebag
** Last update Sun May 29 19:56:58 2016 Dheilly Joss
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "solver.h"
#include "get_maze.h"

void		def_nei(t_fir_end *list)
{
  t_elem	*elem;
  int		i;

  i = 0;
  elem = list->first;
  while (i < list->size)
    {
      find_nei_top(elem);
      find_nei_left(elem);
      find_nei_bot(list, elem);
      find_nei_right(list, elem);
      i = i + 1;
      elem = elem->next;
    }
}

int		use_ret_gnl(t_fir_end *list, char *ret, int len_max, int y)
{
  int		i;

  i = 0;
  if (my_strlen(ret) != len_max)
    return (-1);
  while (i < len_max)
    {
      if (list->size == 0)
	create_list(list, i, y, ret[i]);
      else
	add_case_end(list, i, y, ret[i]);
      i = i + 1;
      if (ret[i] == '\0' && i < len_max - 1)
	return (-1);
    }
  return (0);
}

t_fir_end	*get_maze(int fd)
{
  t_fir_end	*list;
  char		*ret;
  int		len_max;
  int		y;

  y = 0;
  if ((list = malloc(sizeof(t_fir_end))) == NULL)
    exit(EXIT_FAILURE);
  ret = get_next_line(fd);
  len_max = my_strlen(ret);
  init(list);
  list->width = len_max;
  while (ret != NULL)
    {
      if (use_ret_gnl(list, ret, len_max, y) == -1)
	return (NULL);
      free(ret);
      ret = get_next_line(fd);
      y = y + 1;
    }
  free(ret);
  list->height = y;
  def_nei(list);
  return (list);
}
