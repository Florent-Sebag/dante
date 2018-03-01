/*
** linked.c for l in /home/sebag_f/Desktop/rendu/Select
**
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
**
** Started on  Tue Dec  8 17:10:40 2015 Florent Sebag
** Last update Sun May 22 22:42:12 2016 Florent Sebag
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "generator.h"

void		init(t_fir_end *list)
{
  list->first = NULL;
  list->last = NULL;
  list->size = 0;
}

  int		create_list_int(t_fir_end *list, int nb, int x, int y)
{
  t_elem	*elem;

  if ((elem = malloc(sizeof(t_elem))) == NULL)
    exit(42);
  elem->x = x;
  elem->y = y;
  elem->nb = nb;
  elem->prev = elem;
  elem->next = elem;
  list->first = elem;
  list->last = elem;
  list->size = 1;
  return (0);
}

int		rm_case_list(t_fir_end *list, t_elem *elem)
{
  if (list->size == 1)
    {
      list->size = 0;
      return (0);
    }
  if (list->size == 2)
    {
      list->first = elem->next;
      list->last = elem->next;
      elem->next->next = elem->next;
      elem->next->prev = elem->next;
      list->size = 1;
      return (0);
    }
  if (elem == list->first)
    list->first = elem->next;
  if (elem == list->last)
    list->last = elem->prev;
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  list->size = list->size - 1;
  free(elem);
  return (0);
}

int		add_case_end_int(t_fir_end *list, int nb, int x, int y)
{
  t_elem	*new_elem;

  if ((new_elem = malloc(sizeof(t_elem))) == NULL)
    exit(EXIT_FAILURE);
  new_elem->x = x;
  new_elem->y = y;
  new_elem->nb = nb;
  new_elem->next = list->first;
  new_elem->prev = list->last;
  list->first->prev = new_elem;
  list->last->next = new_elem;
  list->last = new_elem;
  list->size = list->size + 1;
  return (0);
}

t_fir_end	*create_linked(int **maze, int height, int width)
{
  int		y;
  int		x;
  t_fir_end	*list;

  list = malloc(sizeof(t_fir_end));
  init(list);
  y = 1;
  x = 1;
  while (y < height)
    {
      while (x < width)
	{
	  if (maze[y][x] == -1)
	    {
	      if (list->size == 0)
		create_list_int(list, maze[y][x], x, y);
	      else
		add_case_end_int(list, maze[y][x], x, y);
	    }
	  x = x + 1;
	}
      x = 1;
      y = y + 1;
    }
  return (list);
}
