/*
** linked_elem.c for h in /home/sebag/Bureau/dante/largeur/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Sun May 22 16:55:58 2016 Florent Sebag
** Last update Sun May 22 21:16:44 2016 Florent Sebag
*/

#include "solver.h"

t_elem		*rm_first_elem(t_fir_end *list)
{
  t_elem	*tmp;
  t_elem	*free_tmp;

  free_tmp = list->first;
  tmp = list->first->file_elem;
  if (list->size == 1)
    {
      free(free_tmp);
      init(list);
      return (tmp);
    }
  if (list->size == 2)
    {
      create_list_elem(list, list->first->next->file_elem);
      free(free_tmp);
      return (tmp);
    }
  list->first = list->first->next;
  list->last->next = list->first;
  list->first->prev = list->last;
  list->size = list->size - 1;
  free(free_tmp);
  return (tmp);
}

int		create_list_elem(t_fir_end *list, t_elem *data)
{
  t_elem	*elem;

  if ((elem = malloc(sizeof(t_elem))) == NULL)
    exit(42);
  elem->file_elem = data;
  elem->prev = elem;
  elem->next = elem;
  list->first = elem;
  list->last = elem;
  list->size = 1;
  return (0);
}

int		add_elem_end(t_fir_end *list, t_elem *data)
{
  t_elem	*new_elem;

  if ((new_elem = malloc(sizeof(t_elem))) == NULL)
    exit(EXIT_FAILURE);
  new_elem->file_elem = data;
  new_elem->next = list->first;
  new_elem->prev = list->last;
  list->first->prev = new_elem;
  list->last->next = new_elem;
  list->last = new_elem;
  list->size = list->size + 1;
  return (0);
}
