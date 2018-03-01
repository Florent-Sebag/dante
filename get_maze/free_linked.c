/*
** free_linked.c for h in /home/sebag/Bureau/dante/get_maze/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Sun May 22 21:20:10 2016 Florent Sebag
** Last update Sun May 22 21:31:05 2016 Florent Sebag
*/

#include "solver.h"

void		free_linked(t_fir_end *list)
{
  int		i;
  t_elem	*tmp;
  t_elem	*elem;

  i = 0;
  if (list->size == 0)
    {
      free(list);
      return ;
    }
  elem = list->first;
  tmp = elem;
  while (i < list->size)
    {
      elem = elem->next;
      free(tmp->nei);
      free(tmp);
      tmp = elem;
      i = i + 1;
    }
  free(list);
}
