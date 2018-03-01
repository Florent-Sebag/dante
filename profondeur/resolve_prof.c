/*
** resolve_larg.c for h in /home/sebag/Bureau/dante/resolve/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Fri May 20 16:02:37 2016 Florent Sebag
** Last update Fri May 27 13:56:56 2016 Dheilly Joss
*/

#include "get_maze.h"
#include "solver.h"

int		resolve_prof(t_fir_end *list, t_elem *elem)
{
  int		i;
  int		indic;

  i = -1;
  indic = 0;
  elem->indic = -2;
  while (++i < 4)
    {
      if (elem->nei[i] != NULL)
	{
	  if (elem->nei[i]->data != 'X' && elem->nei[i]->indic == 0)
	    {
	      if (resolve_prof(list, elem->nei[i]) == -1 && indic <= 0)
		indic = indic - 1;
	      else
		indic = 1;
	    }
	}
    }
  if (indic <= 0 && elem != list->last)
    {
      elem->indic = 0;
      return (-1);
    }
  return (1);
}

void		print_res(t_fir_end *list)
{
  t_elem	*elem;
  int		i;

  i = 1;
  elem = list->first;
  while (i < list->size + 1)
    {
      if (elem->data == 'X')
	printf("%c", elem->data);
      else if (elem->data == '*' && elem->indic != -2)
	printf("*");
      else
	printf("o");
      if (i % list->width == 0)
	printf("\n");
      i = i + 1;
      elem = elem->next;
    }
}

void		init_prof(t_fir_end *list)
{
  resolve_prof(list, list->first);
  print_res(list);
}
