/*
** linked.c for h in /home/sebag/Bureau/dante/recup/
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.eu>
**
** Started on  Fri May 20 14:02:19 2016 Florent Sebag
** Last update Sun May 22 22:35:46 2016 Florent Sebag
*/

#include "get_maze.h"

void		init(t_fir_end *list)
{
  list->first = NULL;
  list->last = NULL;
  list->size = 0;
}

int		create_list(t_fir_end *list, int x, int y, char data)
{
  t_elem	*elem;

  if ((elem = malloc(sizeof(t_elem))) == NULL)
    exit(42);
  if ((elem->nei = malloc(sizeof(t_elem *) * 4)) == NULL)
    exit(EXIT_FAILURE);
  elem->x = x;
  elem->y = y;
  elem->indic = 0;
  elem->data = data;
  elem->prev = elem;
  elem->next = elem;
  list->first = elem;
  list->last = elem;
  list->size = 1;
  return (0);
}

int		add_case_end(t_fir_end *list, int x, int y, char data)
{
  t_elem	*new_elem;

  if ((new_elem = malloc(sizeof(t_elem))) == NULL)
    exit(EXIT_FAILURE);
  if ((new_elem->nei = malloc(sizeof(t_elem *) * 4)) == NULL)
    exit(EXIT_FAILURE);
  new_elem->x = x;
  new_elem->y = y;
  new_elem->data = data;
  new_elem->indic = 0;
  new_elem->next = list->first;
  new_elem->prev = list->last;
  list->first->prev = new_elem;
  list->last->next = new_elem;
  list->last = new_elem;
  list->size = list->size + 1;
  return (0);
}
