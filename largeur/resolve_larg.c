/*
** resolve_larg.c for h in /home/sebag/Bureau/dante/resolve/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Fri May 20 16:02:37 2016 Florent Sebag
** Last update Sun May 29 19:57:38 2016 Dheilly Joss
*/

#include "get_maze.h"
#include "solver.h"

void		add_nei_to_file(t_fir_end *file, t_elem *elem)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if (elem->nei[i] != NULL)
	{
	  if (elem->nei[i]->data != 'X' && elem->nei[i]->indic == 0)
	    {
	      elem->nei[i]->indic = elem->indic + 1;
	      if (file->size == 0)
		create_list_elem(file, elem->nei[i]);
	      else
		add_elem_end(file, elem->nei[i]);
	    }
	}
      i++;
    }
}

t_elem		*find_prev_elem(t_elem *elem, int nb)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if (elem->nei[i] != NULL)
	{
	  if (elem->nei[i]->indic == nb - 1)
	    return (elem->nei[i]);
	}
      i++;
    }
  return (NULL);
}

int		resolve_larg(t_fir_end *list, t_elem *elem, t_fir_end *file)
{
  int		i;

  i = 0;
  while (elem != list->last)
    {
      if (i != 0)
	elem = rm_first_elem(file);
      add_nei_to_file(file, elem);
      i = i + 1;
    }
  i = 0;
  free_linked(file);
  while (elem != list->first)
    {
      i = elem->indic;
      elem->indic = -2;
      elem = find_prev_elem(elem, i);
    }
  elem->indic = -2;
  return (0);
}
